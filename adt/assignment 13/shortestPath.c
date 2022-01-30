#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct vertex {
  int   weight;
  int   data;
  struct vertex *next;
} vertex_t;

typedef struct head {
  vertex_t **table;
} head_t;

typedef struct queue {
  int data;
  struct queue *next;
} queue_t;

head_t *insert_vertex(head_t *tb,int u,int v,int w)
{
    //printf("pass");
    vertex_t *v1 = (vertex_t *)malloc(sizeof(vertex_t));
    vertex_t *v2 = (vertex_t *)malloc(sizeof(vertex_t));
    v1->data = u; v2->data = v;
    v1->next = NULL; v2->next = NULL;
    v1->weight = w; v2->weight = w;
    vertex_t *tmp1,*tmp2;
    if (tb->table[u] == NULL)
        {tb->table[u] = v2;}
    else
        {
            tmp1 = tb->table[u];
            while (tmp1->next != NULL)
                {tmp1 = tmp1->next;}
            tmp1->next = v2;
        }
    if (tb->table[v] == NULL)
        {tb->table[v] = v1;}
    else
        {
            tmp2 = tb->table[v];
            while (tmp2->next != NULL)
                {tmp2 = tmp2->next;}
            tmp2->next = v1;
        }
    return tb;
}

queue_t *enqueue(queue_t *q,int node)
{
  queue_t *queue = (queue_t *)malloc(sizeof (queue_t));
  queue->data = node;
  queue->next = NULL;
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
  tmp = q;
  while (tmp->next!=NULL)
  {
    //printf("data=%d ",tmp->data);
    tmp=tmp->next;
  }
  return tmp->data;
}

int bfs_is_connect(head_t *tb,int s,int t)
{
    int visited_l[700];
    int node, is_connect = -1;
    queue_t *q = NULL;
    visited_l[s] = 1;
    q = enqueue(q,s);
    while (1)
    {
      //printf("pass");   
      node = find_q(q);
      //printf("node=%d\n",node);
      if (node == t)
        {is_connect = 1; break;}
      q = dequeue(q);
      vertex_t *tmp;
      tmp = tb->table[node];
      while (tmp!=NULL)
      {   
        //printf("pass"); 
        if (visited_l[tmp->data]!=1)
        {
          visited_l[tmp->data] = 1;
          //printf("tmp->data = %d\n",tmp->data);
          q = enqueue(q,tmp->data);
        }
        tmp = tmp->next;
      }
      if (q==NULL && tmp==NULL)
        {break;}
    }
    //printf("%d\n",is_connect);
    return is_connect;
}

int shortest_path(head_t *tb,int s,int t,int n)
{
  int shortest[n],visited_l[n];
  int i,j,min,dt,stop,vertex;
  for (i=0;i<n;i++)
    {
      if (tb->table[i]==NULL)
        {visited_l[i] = 1;}
      shortest[i] = 1000;
    }
  shortest[s] = 0;

  while (1)
  {
    //printf("pass");
    stop = 1;
    min = 999;
    for (i=0;i<n;i++)
    {
      //printf("shortest=%d ",shortest[i]);
      if (shortest[i]<min && visited_l[i]!=1)
        {min = shortest[i]; vertex = i;}
    }
    //printf("min=%d\n",min);
    vertex_t *tmp = tb->table[vertex];
    while (tmp!=NULL)
      {    
        if (visited_l[tmp->data]!=1)
        {
          dt = (shortest[vertex]) + (tmp->weight);
          //printf("dt=%d\n",dt);
          if (dt<shortest[tmp->data])
            {shortest[tmp->data] = dt;}
        }
        tmp = tmp->next;
        //printf("pass");
      }
    visited_l[vertex] = 1;

    if (visited_l[s]==1 && visited_l[t]==1)
      {break;}
    //check if all vertex is visited
    for (j=0;j<n;j++)
    {
      if (visited_l[j] != 1)
        {stop = -1;}
    }
    if (stop==1)
      {break;}
  }
  return shortest[t];
}

int main()
{
    head_t *tb = (head_t *)malloc(sizeof(head_t));
    int n,m,p,u,v,w,s,t,i,is_connect,path;
    scanf("%d %d %d",&n,&m,&p);
    tb->table = (vertex_t **)malloc(sizeof(vertex_t)*n);
    for (i=0;i<n;i++)
        {tb->table[i] = NULL;}
    for (i=0;i<m;i++)
    {
        scanf("%d %d %d",&u,&v,&w);
        tb = insert_vertex(tb,u,v,w);
    } 
    for (i=0;i<p;i++)
    {
        scanf("%d %d",&s,&t);
        if (s==t)
          {printf("0\n");}
        else
        {
          is_connect = bfs_is_connect(tb,s,t);
          //printf("pass");
          if (is_connect == -1)
            { printf("-1\n"); }
          else
            {
              path = shortest_path(tb,s,t,n);
              printf("%d\n",path);
            }
        }
    }
}