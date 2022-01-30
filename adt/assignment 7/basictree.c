#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *next_sib;
    struct node *first_c;
} node_t;
typedef node_t tree_t;

typedef struct queue {
  int data;
  struct queue *next;
} queue_t;

typedef struct stack {
  int data;
  struct stack *next;
} stack_t;

tree_t *extra_search(tree_t *t,int v)
{
    tree_t *pos;
    if ((t==NULL)||(t->value==v))
    {
        return t;
    }
    pos = extra_search(t->first_c,v);
    if (pos != NULL)
    {
        return pos;
    }
    else
    {
        return extra_search(t->next_sib,v);
    }
}

tree_t *attach(tree_t *t,int p,int c)
{   
    tree_t *pos;
    node_t *node = (node_t *)malloc(sizeof (node_t));
    node->value = c;
    node->next_sib = NULL;
    node->first_c = NULL;
    if (t == NULL)
    {
        t = node;
        return t;
    }
    pos = extra_search(t,p);
    if (pos->first_c==NULL)
    {
      pos->first_c = node;
      return t;
    }
    pos = pos->first_c;
    while (pos->next_sib != NULL)
    {
      pos = pos->next_sib;
    }
    pos->next_sib = node;
    return t;
}

tree_t *before(tree_t *t,tree_t *pos)
{
  tree_t *tmp1,*tmp2;
  if (t==NULL)
    {return NULL;}
  if (t->first_c==pos)
    {return t;}
  else if (t->next_sib==pos)
    {return t;}
  tmp1 = before(t->first_c,pos);
  if (tmp1 != NULL)
    {return tmp1;}
  tmp2 = before(t->next_sib,pos);
  return tmp2;
}

tree_t *detach(tree_t *t,int node)
{
  tree_t *pos1, *pos2;
  pos1 = extra_search(t,node);
  pos2 = before(t,pos1);
  if (pos2->first_c==pos1)
  {
    pos2->first_c = pos1->next_sib;
  }
  else if (pos2->next_sib==pos1)
  {
    pos2->next_sib = pos1->next_sib;
  }
  return t; 
}

int search(tree_t *t,int node)
{
  tree_t *pos;
  pos = extra_search(t,node);
  if (pos==NULL)
  {
    return 0;
  }
  return 1;
}

int degree(tree_t *t,int node)
{
  tree_t *pos;
  int n=0;
  pos = extra_search(t,node);
  if (pos==NULL)
  {
    return n;
  }
  if (pos->first_c==NULL)
  {
    return n;
  }
  pos = pos->first_c;
  n += 1;
  while (pos->next_sib!=NULL)
  {
    pos = pos->next_sib;
    n += 1;
  }
  return n;
}

int is_root(tree_t *t,int node)
{
  if (t->value==node)
  {
    return 1;
  }
  return 0;
}

int is_leaf(tree_t *t,int node)
{
  tree_t *pos;
  pos = extra_search(t,node);
  if (pos->first_c==NULL)
  {
    return 1;
  }
  return 0;
}

void siblings(tree_t *t,int node)
{
  tree_t *pos1, *pos2, *pos3;
  pos1 = extra_search(t,node);
  pos2 = before(t,pos1);
  if ((t->value==node)||((pos1->next_sib==NULL)&&(pos2->first_c==pos1)))
    {printf("\n");}
  else if (pos2->first_c==pos1)
  {
    while (1)
    {
      if (pos1->next_sib==NULL)
      {
        if (pos1->value!=node)
          {printf("%d\n",pos1->value);}
        break;
      }
      if (pos1->value!=node)
        {printf("%d ",pos1->value);}
      pos1 = pos1->next_sib;
    }
  }
  else if (pos2->next_sib==pos1)
  {
    while (1)
    {
      pos3 = before(t,pos2);
      if (pos3->first_c==pos2)
        {break;}
      pos2 = before(t,pos2);
    }
    while (1)
    {
      if (pos2->next_sib==NULL)
      {
        if (pos2->value!=node)
          {printf("%d\n",pos2->value);}
        break;  
      }
      if (pos2->value!=node)
        {printf("%d ",pos2->value);}
      pos2 = pos2->next_sib;
    } 
  }
}

int depth(tree_t *t,int node)
{
  int n=0;
  tree_t *pos1, *pos2;
  pos1 = extra_search(t,node);
  if (t->value==node)
    {return n;}
  pos2 = before(t,pos1);
  while (1)
  {
    if (pos2==t)
    {
      return n+1;
    }
    if (pos2->first_c==pos1)
      {n+=1;}
    pos2 = before(t,pos2);
    pos1 = before(t,pos1);
  }
}

stack_t *append(stack_t *s,int value)
{
  stack_t *stack = (stack_t *)malloc(sizeof (stack_t));
  stack->data = value;
  if (s==NULL)
    {s = stack;}
  else
    {
      stack->next = s;
      s = stack;
    }
  return s;
}

void print_path(tree_t *t,int start,int end)
{
  if (start==end)
  {
    printf("%d\n",start);
    return;
  }
  stack_t *s = NULL;
  tree_t *pos1, *pos2, *tmp;
  pos1 = extra_search(t,start);
  pos2 = extra_search(t,end);
  tmp = before(t,pos2);
  s = append(s,pos2->value);
  while (1)
  {
    if (tmp==pos1)
    {
      s = append(s,tmp->value);
      break;
    }
    if (tmp->first_c==pos2)
    {
      s = append(s,tmp->value);
    }
    tmp = before(t,tmp);
    pos2 = before(t,pos2);  
  }
  stack_t *print;
  print=s;
  while (print->next!=NULL)
  {
    printf("%d ",print->data);
    print = print->next;
  }
  printf("%d\n",print->data);
}

int path_length(tree_t *t,int start,int end)
{
  int n=1;
  tree_t *pos1, *pos2, *tmp;
  pos1 = extra_search(t,start);
  pos2 = extra_search(t,end);
  tmp = before(t,pos2);
  if (start==end)
  {
    return n;
  }
  while (1)
  {
    if (tmp==pos1)
    {
      n += 1;
      break;
    }
    if (tmp->first_c==pos2)
    {
      n += 1;
    }
    tmp = before(t,tmp);
    pos2 = before(t,pos2);  
  }
  return n;
}

void ancestor(tree_t *t,int node)
{
  if (t->value==node)
  {
    printf("%d\n",t->value);
    return;
  }
  stack_t *s = NULL;
  tree_t *pos, *tmp;
  pos = extra_search(t,node);
  tmp = before(t,pos);
  s = append(s,pos->value);
  while (1)
  {
    if (tmp==t)
    {
      s = append(s,tmp->value);
      break;
    }
    if (tmp->first_c==pos)
    {
      s = append(s,tmp->value);
    }
    tmp = before(t,tmp);
    pos = before(t,pos);  
  }
  stack_t *print;
  print=s;
  while (print->next!=NULL)
  {
    printf("%d ",print->data);
    print = print->next;
  }
  printf("%d\n",print->data);
}

queue_t *enqueue(queue_t *q,int node)
{
  queue_t *queue = (queue_t *)malloc(sizeof (queue_t));
  queue->data = node;
  if (q==NULL)
    {q = queue;}
  else
    {
      queue->next = q;
      q = queue;
    }
  return q;
}

queue_t *dequeue(queue_t *q)
{
  queue_t *tmp1, *tmp2;
  tmp1 = q; tmp2 = q;
  if (q->next==NULL)
  {
    q = NULL;
    free(tmp1);
    return q;
  }
  while (1)
  {
    if (tmp1->next==NULL)
    {
      tmp2->next = NULL;
      free(tmp1);
      return q;
    }
    tmp2 = tmp1;
    tmp1 = tmp1->next;
  }
}

int find_q(queue_t *q)
{
  queue_t *tmp;
  int node;
  tmp = q;
  while (tmp->next!=NULL)
  {
    tmp=tmp->next;
  }
  return tmp->data;
}

void descendant(tree_t *t,int start)
{
  int node;
  tree_t *tmp;
  queue_t *q = NULL;
  tmp = extra_search(t,start);
  q = enqueue(q,tmp->value);
  tree_t *pos;

  while (q!=NULL)
  {
    node = find_q(q);
    printf("%d ",node);
    q = dequeue(q);
    pos = extra_search(t,node);
    if (pos->first_c!=NULL)
    {
      pos = pos->first_c;
      while (pos->next_sib!=NULL)
      {
        q = enqueue(q,pos->value);
        pos = pos->next_sib;
      }
      q = enqueue(q,pos->value);
    }
  }
  printf("\n");
}

void bfs(tree_t *t)
{
  int node;
  queue_t *q = NULL;
  q = enqueue(q,t->value);
  tree_t *pos;

  while (q!=NULL)
  {
    node = find_q(q);
    printf("%d ",node);
    q = dequeue(q);
    pos = extra_search(t,node);
    if (pos->first_c!=NULL)
    {
      pos = pos->first_c;
      while (pos->next_sib!=NULL)
      {
        q = enqueue(q,pos->value);
        pos = pos->next_sib;
      }
      q = enqueue(q,pos->value);
    }
  }
  printf("\n");
}

void dfs(tree_t *t)
{
  if ((t->first_c==NULL)&&(t->next_sib==NULL))
  {
    printf("%d ",t->value);
    return;
  }
  printf("%d ",t->value);
  if (t->first_c!=NULL)
  {
    dfs(t->first_c);
  }
  if (t->next_sib!=NULL)
  {
  dfs(t->next_sib);
  }
  printf("\n");
}

stack_t *push(stack_t *s,int value)
{
  stack_t *stack = (stack_t *)malloc(sizeof (stack_t));
  stack->data = value;
  stack->next = NULL;
  if (s==NULL)
  {
    s = stack;
    return s;
  }
  stack->next = s;
  s = stack;
  return s;
}

stack_t *pop(stack_t *s)
{
  stack_t *tmp;
  if (s==NULL)
  {
    return s;
  }
  tmp = s;
  s = s->next;
  free(tmp);
  return s;
}

void print_tree(tree_t *t)
{
  int d, i;
  tree_t *pos;
  stack_t *s = NULL;
  s = push(s,t->value);
  while (s!=NULL)
  {
    stack_t *rv = NULL;
    d = depth(t,s->data);
    for (i=0;i<d;i++)
    {
      printf("    ");
    }
    printf("%d\n",s->data);

    pos = extra_search(t,s->data);
    s = pop(s);
    if (pos->first_c!=NULL)
    {
      //printf("pass");
      pos = pos->first_c;
      while (pos->next_sib!=NULL)
      {
        //printf("pass\n");
        rv = push(rv,pos->value);
        pos = pos->next_sib;
      }
      rv = push(rv,pos->value);
      while (1)
      {
        s = push(s,rv->data);
        if (rv->next==NULL)
          {break;}
        rv = rv->next;
      }
    }
  }
}

int main(void) {
  tree_t *t = NULL;
  int n, i, command;
  int parent, child, node, start, end;

  scanf("%d", &n);
  for (i=0; i<n; i++) {
    scanf("%d", &command);
    switch(command) {
      case 1:
        scanf("%d %d", &parent, &child);
        t = attach(t, parent, child);
        break;
      case 2:
        scanf("%d", &node);
        t = detach(t, node);
        break;
      case 3:
        scanf("%d", &node);
        printf("%d\n", search(t, node));
        break;
      case 4:
        scanf("%d", &node);
        printf("%d\n", degree(t, node));
        break;
      case 5:
        scanf("%d", &node);
        printf("%d\n", is_root(t, node));
        break;
      case 6:
        scanf("%d", &node);
        printf("%d\n", is_leaf(t, node));
        break;
      case 7:
        scanf("%d", &node);
        siblings(t, node);
        break;
      case 8:
        scanf("%d", &node);
        printf("%d\n", depth(t, node));
        break;
      case 9:
        scanf("%d %d", &start, &end);
        print_path(t, start, end);
        break;
      case 10:
        scanf("%d %d", &start, &end);
        printf("%d\n", path_length(t, start, end));
        break;
      case 11:
        scanf("%d", &node);
        ancestor(t, node);
        break;
      case 12:
        scanf("%d", &node);
        descendant(t, node);
        break;
      case 13:
        bfs(t);
        break;
      case 14:
        dfs(t);
        break;
      case 15:
        print_tree(t);
        break; 
    }
  }
  return 0;
}