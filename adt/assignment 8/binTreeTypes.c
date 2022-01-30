#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "week8.h"

#ifndef __bin_tree__
typedef struct node {
  int    data;  
  struct node *left;
  struct node *right;
} node_t;

typedef node_t tree_t;
#endif

int is_full(tree_t *t)
{
    int L,R;
    if (t->left==NULL && t->right==NULL)
    {
      return 1;
    }
    if ((t->left==NULL && t->right!=NULL)||(t->left!=NULL && t->right==NULL))
    {
      return 0;
    }
    L = is_full(t->left);
    R = is_full(t->right);
    if (L==0||R==0)
      {return 0;}
    return 1;
}

int height(tree_t *t)
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

int size(tree_t *t)
{
  int L,R;
  if (t==NULL)
    {return 0;}
  L = size(t->left);
  R = size(t->right);
  return L+R+1;
}

int is_perfect(tree_t *t)
{
  int s,h;
  s = size(t);
  h = height(t);
  if (pow(2,h+1)-1==s)
  {
    return 1;
  }
  return 0;
}

typedef struct mynode {
  int value;
  struct mynode *next;
} mynode_t;

mynode_t *append(mynode_t *sn,int n)
{
  mynode_t *mynode = (mynode_t *)malloc(sizeof (mynode_t));
  mynode->value = n;
  mynode->next = NULL;
  if (sn==NULL)
    {sn = mynode;}
  else
    {
      mynode->next = sn;
      sn = mynode;
    }
  return sn;
}

int find_in_list(mynode_t *sn)
{
  mynode_t *tmp;
  tmp = sn;
  while (tmp->next!=NULL)
  {
    tmp=tmp->next;
  }
  return tmp->value;
}

mynode_t *dequeue(mynode_t *sn)
{
  mynode_t *tmp1, *tmp2;
  tmp1 = sn; tmp2 = sn;
  if (sn->next==NULL)
  {
    sn = NULL;
    free(tmp1);
    return sn;
  }
  while (1)
  {
    if (tmp1->next==NULL)
    {
      tmp2->next = NULL;
      free(tmp1);
      return sn;
    }
    tmp2 = tmp1;
    tmp1 = tmp1->next;
  }
}

tree_t *extra_search(tree_t *t,int v)
{
    tree_t *pos;
    if ((t==NULL)||(t->data==v))
    {
        return t;
    }
    pos = extra_search(t->left,v);
    if (pos != NULL)
    {
        return pos;
    }
    else
    {
        return extra_search(t->right,v);
    }
}

int is_complete(tree_t *t)
{
  int n,count=1;
  mynode_t *sn = NULL;
  sn = append(sn,t->data);
  tree_t *tmpL, *tmpR;
  while (sn!=NULL)
  {
    n = find_in_list(sn);
    sn = dequeue(sn);
    tmpL = extra_search(t,n); tmpR = tmpL;
    if ((tmpL->left==NULL && tmpR->right!=NULL) && (count!=size(t)))
      {return 0;}
    if (tmpL->left == NULL && tmpR->right == NULL && count!=size(t))
      {return 0;}
    if ((tmpL->left!=NULL && tmpR->right==NULL) && count+1!=size(t))
      {return 0;}
    if (tmpL->left!=NULL)
    {
      tmpL = tmpL->left;
      sn = append(sn,tmpL->data);
      count += 1;    
    }
    if (tmpR->right!=NULL)
    {
      tmpR = tmpR->right;
      sn = append(sn,tmpR->data);
      count += 1;
    }
    if (count==size(t))
      {return 1;}
  }
}


int is_degenerate(tree_t *t)
{
  int ans;
  tree_t *tmp;
  tmp = t;
  if (t->left!=NULL && t->right!=NULL)
    {return 0;}
  else if (t->left==NULL && t->right==NULL)
    {return 1;}
  
  if (t->left!=NULL)
  {
    tmp = tmp->left;
    if (tmp->left!=NULL && tmp->right!=NULL)
      {return 0;} 
    ans = is_degenerate(t->left);
    if (ans==0)
      {return 0;}
  }
  else if (t->right!=NULL)
  {
    tmp = tmp->right;
    if (tmp->left!=NULL && tmp->right!=NULL)
      {return 0;}
    ans = is_degenerate(t->right);
    if (ans==0)
      {return 0;}
  }
  return 1;
}

int is_skewed(tree_t *t)
{
  int L=1,R=1;
  tree_t *tmp;
  tmp = t;
  if (t->left==NULL && t->right==NULL)
    {return 1;}
  if (t->left!=NULL && t->right!=NULL)
    {return 0;}
  else if (t->left!=NULL)
  {
    tmp = tmp->left;
    if (tmp->right!=NULL)
      {return 0;}
    L = is_skewed(t->left);
  }
  else if (t->right!=NULL)
  {
    tmp = tmp->right;
    if (tmp->left!=NULL)
      {return 0;}
    R = is_skewed(t->right);
  }
  if (L==0||R==0)
    {return 0;}
  return 1;
}

int main(void) {
  tree_t *t = NULL;
  int n, i;
  int parent, child;
  int branch; // 0 root, 1 left, 2 right

  scanf("%d", &n);
  for (i=0; i<n; i++) {
    scanf("%d %d %d", &parent, &child, &branch);
    t = attach(t, parent, child, branch);
  }

  printf("%d %d %d %d %d\n", is_full(t), is_perfect(t), is_complete(t), is_degenerate(t), is_skewed(t));

  return 0;
}