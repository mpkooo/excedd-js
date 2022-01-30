#include <stdio.h>
#include <stdlib.h>
#include "week9.h"

#ifndef __avl_tree__
typedef struct node {
  int    data;
  int    height;
  struct node *left;
  struct node *right;
} node_t;

typedef node_t avl_t;
#endif

int height(avl_t *t)
{
  int hL,hR;
  if (t==NULL)
    {return -1;}
  hL = height(t->left);
  hR = height(t->right);
  if (hL>hR)
    {return hL+1;}
  return hR+1;
}

int max(int x,int y)
{
    if (x>y)
        {return x;}
    return y;
}

int find_unbalance(avl_t *t)
{
    if (t==NULL)
        {return 0;}
    else
        {return height(t->left)-height(t->right);}
}

avl_t *rotate_right(avl_t *t)
{
    avl_t *tmp1, *tmp2;
    tmp1 = t->left; tmp2 = tmp1->right;

    tmp1->right = t;
    t->left = tmp2;

    t->height = 1 + max(height(t->left),height(t->right));
    tmp1->height = 1 + max(height(tmp1->left),height(tmp1->right));

    return tmp1;
}

avl_t *rotate_left(avl_t *t)
{
    avl_t *tmp1, *tmp2;
    tmp1 = t->right; tmp2 = tmp1->left;

    tmp1->left = t;
    t->right = tmp2;

    t->height = 1 + max(height(t->left),height(t->right));
    tmp1->height = 1 + max(height(tmp1->left),height(tmp1->right));

    return tmp1;
}

avl_t *insert(avl_t *t,int data)
{
    avl_t *node = (avl_t *)malloc(sizeof (avl_t));
    node->data = data;
    node->left = NULL; node->right = NULL; 
    if (t==NULL)
    {       
        t = node;
        {return t;}
    }
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
    t->height = 1 + max(height(t->left),height(t->right));

    if ((find_unbalance(t) > 1) && (data < t->left->data)) //ll
    {
        return rotate_right(t);
    }
    else if ((find_unbalance(t) < -1) && (data > t->right->data)) //rr
    {
        return rotate_left(t);
    }
    else if ((find_unbalance(t) > 1) && (data > t->left->data)) //lr
    {
        t->left = rotate_left(t->left);
        return rotate_right(t);
    }
    else if ((find_unbalance(t) < -1) && (data < t->right->data)) //rl
    {
        t->right = rotate_right(t->right);
        return rotate_left(t);
    }

    return t;
}

avl_t *findmin(avl_t *t)
{
    avl_t *tmp;
    tmp = t;
    while (tmp->left != NULL)
        {tmp = tmp->left;}
    return tmp;
}

avl_t *delete(avl_t *t,int data)
{    
    if (t==NULL)
        {return t;}

    if (data < t->data)
        {t->left = delete(t->left,data);}
    else if (data > t->data)
        {t->right = delete(t->right,data);}
    else
    {
        avl_t *tmp;
        if (t->left==NULL || t->right==NULL)
        {
            if (t->left!=NULL)
                {tmp = t->left;}
            tmp = t->right;

            if (tmp==NULL)
            {
                tmp = t;
                t = NULL;
            }
            else
            {
                *t = *tmp;
                free(tmp);
            }    
        }
        else
        {
            tmp = findmin(t->right);
            t->data = tmp->data;
            t->right = delete(t->right,tmp->data); 
        }
    }
    if (t==NULL)
        {return t;}

    t->height = 1 + max(height(t->left),height(t->right));

    if ((find_unbalance(t) > 1) && find_unbalance(t->left)>=0) //ll
    {
        return rotate_right(t);
    }
    else if ((find_unbalance(t) < -1) && find_unbalance(t->right)<=0) //rr
    {
        return rotate_left(t);
    }
    else if ((find_unbalance(t) > 1) && find_unbalance(t->left)<0) //lr
    {
        t->left = rotate_left(t->left);
        return rotate_right(t);
    }
    else if ((find_unbalance(t) < -1) && find_unbalance(t->right)>0) //rl
    {
        t->right = rotate_right(t->right);
        return rotate_left(t);
    }
    return t;
}

int main(void) {
  avl_t *t = NULL;
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
        print_tree(t);
        break;
    }
  }
  return 0;
}