#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int    data;
  struct node *left;
  struct node *right;
} node_t;

typedef node_t bst_t;

bst_t *insert(bst_t *t,int data)
{   
    bst_t *node = (bst_t *)malloc(sizeof (bst_t));
    node->data = data;
    node->left = NULL; node->right = NULL; 
    if (t==NULL)
    {       
        t = node;
        {return t;}
    }
    if (t->data == data)
        {return t;}

    if (data < (t->data))
    {
        if (t->left == NULL)
        {
            t->left = node;
            return t;
        }
        t->left = insert(t->left,data);
    }
    else if (data > (t->data))
    {
        if (t->right == NULL)
        { 
            t->right = node;
            return t;
        }
        t->right = insert(t->right,data);
    }
    return t;
}

int find(bst_t *t,int data)
{
    if (t==NULL)
    {
        return 0;
    }
    if (t->data == data)
    {
        return 1;
    }

    if (data < (t->data))
    {
        if (t->left != NULL)
        {
            return find(t->left,data);
        }
    }
    else if (data > (t->data))
    {
        if (t->right != NULL)
        {
            return find(t->right,data);
        }
    }
}

int find_min(bst_t *t)
{
    if (t->left == NULL)
    {
        return t->data;
    }
    find_min(t->left);
}

int find_max(bst_t *t)
{
    if (t->right == NULL)
    {
        return t->data;
    }
    find_max(t->right);
}

bst_t *findwhere(bst_t *t,int data)
{
    if (t->data == data)
    {
        return t;
    }

    if (data < (t->data))
    {
        if (t->left != NULL)
        {
            return findwhere(t->left,data);
        }
    }
    else if (data > (t->data))
    {
        if (t->right != NULL)
        {
            return findwhere(t->right,data);
        }
    }
}

bst_t *before(bst_t *t,bst_t *pos)
{
  bst_t *tmp1,*tmp2;
  if (t==NULL)
    {return NULL;}
  if (t->left==pos)
    {return t;}
  else if (t->right==pos)
    {return t;}
  tmp1 = before(t->left,pos);
  if (tmp1 != NULL)
    {return tmp1;}
  tmp2 = before(t->right,pos);
  return tmp2;
}

bst_t *delete(bst_t *t,int data)
{
    bst_t *tmp1, *tmp2;
    if (t->data==data && t->left!=NULL && t->right==NULL)
    {
        tmp1 = t; tmp2 = t;
        t = t->left;
        tmp1->left = NULL;
    }
    
    else if (t->data==data && t->left==NULL && t->right!=NULL)
    {
        tmp1 = t; tmp2 = t;
        t = t->right;
        tmp1->right = NULL;
    }

    else 
    {
        tmp1 = findwhere(t,data);
        tmp2 = before(t,tmp1);
        if (tmp1->left==NULL && tmp1->right==NULL)
        {
            if (tmp1->data < tmp2->data)
            {
                tmp2->left = NULL;
                tmp1->left = NULL; tmp1->right = NULL;
            }
            else if (tmp1->data > tmp2->data)
            {
                tmp2->right = NULL;
                tmp1->left = NULL; tmp1->right = NULL;
            }
        }
        else if (tmp1->left!=NULL && tmp1->right!=NULL)
        {   
            int min;
            min = find_min(tmp1->right);
            t = delete(t,min);
            tmp1->data = min; 
        }
        else if (tmp1->left!=NULL || tmp1->right!=NULL)
        {
            if (tmp1->left != NULL)
            {
                if (tmp1->data < tmp2->data)
                {
                    tmp2->left = tmp1->left;
                    tmp1->left = NULL; tmp1->right = NULL;
                }
                else if (tmp1->data > tmp2->data)
                {
                    tmp2->right = tmp1->left;
                    tmp1->left = NULL; tmp1->right = NULL;
                }
            }
            else if (tmp1->right != NULL)
            {
                if (tmp1->data < tmp2->data)
                {
                    tmp2->left = tmp1->right;
                    tmp1->left = NULL; tmp1->right = NULL;
                }
                else if (tmp1->data > tmp2->data)
                {
                    tmp2->right = tmp1->right;
                    tmp1->left = NULL; tmp1->right = NULL;
                }
            }
        }
    }
    return t;
}

int main(void) {
  bst_t *t = NULL;
  int   n, i;
  int   command, data;

  scanf("%d", &n);
  for (i=0; i<n; i++) {
    scanf("%d", &command);
    switch (command) {
      case 1:
        scanf("%d", &data);
        t = insert(t, data);
        break;
      case 2:
        scanf("%d", &data);
        t = delete(t, data);
        break;
      case 3:
        scanf("%d", &data);
        printf("%d\n", find(t, data));
        break;
      case 4:
        printf("%d\n", find_min(t));
        break;
      case 5:
        printf("%d\n", find_max(t));
        break;
    }
  }
  return 0;
}