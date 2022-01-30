#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  char *data;
  int f;
  struct node *left;
  struct node *right;
} node_t;

typedef struct heap {
  node_t **array;
  int myindex;
  int last_index;
} heap_t;

heap_t *insert(heap_t *t, char text[20],int f)
{
    int i,j;
    node_t *tmp;
    node_t *node = (node_t *)malloc(sizeof(node_t));
    node->data = text;
    node->f = f;
    node->left = NULL;
    node->right = NULL;

    t->array[t->myindex] = node;
    i = t->myindex;
    j = i;
    
    while (1)
    {
        if (t->array[j]->f >= t->array[(j-1)/2]->f)
            {break;}
        else 
        {
            tmp = t->array[j];
            t->array[j] = t->array[(j-1)/2];
            t->array[(j-1)/2] = tmp;
        }
        j = (j-1)/2;
    }
    t->myindex += 1;
    return t;
}


/*void bfs(heap_t *t)
{
    int i;
    for (i=0;i<t->last_index;i++)
    {
        printf("%s ",t->array[i]->data);
    }
}*/

heap_t *delete_min(heap_t *t)
{
    //insert new node
    node_t *node = (node_t *)malloc(sizeof(node_t));
    node->left = NULL;
    node->right = NULL;
    int count=0,fl,fr,fl2,fr2;
    while (count<2)
    {
        count += 1;
        //printf("count = %d\n",count);
        int i=0,j;
        node_t *tmp;
        while (1)
        {
            if ((t->array[i+1]==NULL)||(i+1==t->last_index))
                {break;}
            i = i+1;
        }
        //printf("i = %d\n",i);

        if (count==1)
        {
            node->left = t->array[0];
            fl2 = t->array[0]->f;
        }
        else if (count==2)
        {
            node->right = t->array[0];
            fr2 = t->array[0]->f;
        }
        t->array[0] = t->array[i];
        t->array[i] = NULL;
        t->last_index -= 1;
        j = 0;
        //printf("last index = %d\n",t->last_index);
    
        while ((2*j)+2 <= t->last_index)
        {
            if (t->array[(2*j)+1] == NULL)
                {fl = 1234;}
            else 
                {fl = t->array[(2*j)+1]->f;}
    
            if (t->array[(2*j)+2] == NULL)
                {fr = 1234;}
            else 
                {fr = t->array[(2*j)+2]->f;}

            if ((t->array[j]->f <= fl) && (t->array[j]->f <= fr)) 
                {break;}
            else if (fl <= fr)
            {
                tmp = t->array[(2*j)+1];
                t->array[(2*j)+1] = t->array[j];
                t->array[j] = tmp;
                j = (2*j)+1;
                continue;
            }
            else 
            {
                tmp = t->array[(2*j)+2];
                t->array[(2*j)+2] = t->array[j];
                t->array[j] = tmp;
                j = (2*j)+2;
                continue;
            }
        }
    }
    //printf("index = %d\n",t->last_index);
    node->f = fl2+fr2;
    t->array[t->last_index] = node;
    int a,b;
    b = t->last_index;
    node_t *tmp2;
    while (1)
    {
        if ((b-1)/2<0)
            {break;}
        else if ((t->array[(b-1)/2]->f) > (t->array[b]->f))
        {
            tmp2 = t->array[b];
            t->array[b] = t->array[(b-1)/2];
            t->array[(b-1)/2] = tmp2;
            b = (b-1)/2;
        }
        else
            {break;}
    }
    t->last_index += 1;
    return t;
}

void dfs(node_t *t,int arr[1000],int index_arr)
{
    int i;
  if (t->left!=NULL)
  {
    arr[index_arr] = 0;
    dfs(t->left,arr,index_arr + 1);
  }
  
  if (t->right!=NULL)
  {
    arr[index_arr] = 1;
    dfs(t->right,arr,index_arr + 1);
  }

    if ((t->left==NULL)&&(t->right==NULL))
  {
      if (t->data==NULL)
      {
          return;
      }
    printf("%s: ",t->data);
    for (i=0;i<index_arr;i++)
    {
        printf("%d",arr[i]);
    }
    printf("\n");
    return;
  }
}

/*void checkdfs(node_t *t)
{
  if ((t->left==NULL)&&(t->right==NULL))
  {
    printf("%s ",t->data);
    return;
  }
  printf("%s ",t->data);
  if (t->left!=NULL)
  {
    checkdfs(t->left);
  }
  if (t->right!=NULL)
  {
  checkdfs(t->right);
  }
  printf("\n");
}*/

int main()
{
    int n,i,f,arr[1000],index_arr=0;
    scanf("%d",&n);
    char text[n][20];
    heap_t *t = (heap_t *)malloc(sizeof(heap_t));
    t->array = (node_t **)malloc(t->last_index*sizeof(node_t));
    t->myindex = 0;
    t->last_index = n;

    for (i=0;i<n;i++)
    {
        scanf("%s %d",text[i],&f);
        t = insert(t,text[i],f);
    }
    //bfs(t);
    while (t->last_index > 1)
        {t = delete_min(t);}
    //printf("pass");
    //checkdfs(t->array[0]);
    dfs(t->array[0],arr,index_arr);
}