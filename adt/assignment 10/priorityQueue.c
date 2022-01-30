#include <stdio.h>
#include <stdlib.h>

typedef struct heap {
  int *data;
  int last_index;
} heap_t;

heap_t *init_heap(int m)
{
    heap_t *t = (heap_t *)malloc(sizeof(heap_t));
    int i;
    t->data = (int *)malloc(m*sizeof(int));
    t->last_index = m;
    for (i=0;i<m;i++)
    {
        t->data[i] = -1;
    }
    return t;
}

void insert(heap_t *t,int value)
{
    int i,j,tmp;
    for (i=0;i<(t->last_index);i++)
    {
        if (t->data[i]==-1)
        {
            t->data[i] = value;
            j = i;
            while (1)
            {
                //printf("j = %d\n",j);
                if ((j-1)/2<0)
                    {break;}
                else if (t->data[(j-1)/2] < t->data[j])
                {
                    //printf("pass");
                    tmp = t->data[j];
                    t->data[j] = t->data[(j-1)/2];
                    t->data[(j-1)/2] = tmp;
                    j = (i-1)/2;
                }
                else
                    {break;}
            }
            break;
        }
        //printf("%d ",t->data[i]);
    }
}

void delete_max(heap_t *t)
{   int i=0,j,tmp;
    while (1)
    {
        if ((t->data[i+1]==-1)||(i+1==t->last_index))
            {break;}
        i = i+1;
    }
    t->data[0] = t->data[i];
    t->data[i] = -1;
    j = 0;
    while (1)
    {
        if ((2*j)+1 >= t->last_index)
            {break;}
        else if (t->data[j] < t->data[(2*j)+1])
        {
            tmp = t->data[j];
            t->data[j] = t->data[(2*j)+1];
            t->data[(2*j)+1] = tmp;
            j = (2*j)+1;
            continue;
        }
        else if ((2*j)+2 >= t->last_index)
            {break;}
        else if (t->data[j] < t->data[(2*j)+2])
        {
            tmp = t->data[j];
            t->data[j] = t->data[(2*j)+2];
            t->data[(2*j)+2] = tmp;
            j = (2*j)+2;
            continue;           
        }
        else
            {break;}
    }
}

int find_max(heap_t *t)
{
    return t->data[0];
}

void update_key(heap_t *t,int old_key,int new_key)
{   
    int i,j,tmp;
    for (i=0;i<t->last_index;i++)
    {
        if (t->data[i]==old_key)
            {t->data[i] = new_key;}

    if ((t->data[i] < t->data[(2*j)+1])||(t->data[j] < t->data[(2*j)+2]))
    {
        j = i;
        while (1)
        {
            if ((2*j)+1 >= t->last_index)
                {break;}
            else if (t->data[j] < t->data[(2*j)+1])
            {
                tmp = t->data[j];
                t->data[j] = t->data[(2*j)+1];
                t->data[(2*j)+1] = tmp;
                j = (2*j)+1;
                continue;
            }
            else if ((2*j)+2 >= t->last_index)
                {break;}
            else if (t->data[j] < t->data[(2*j)+2])
            {
                tmp = t->data[j];
                t->data[j] = t->data[(2*j)+2];
                t->data[(2*j)+2] = tmp;
                j = (2*j)+2;
                continue;           
            }
            else
                {break;}
        }
    }
    else if (t->data[(i-1)/2] < t->data[i])
    {
        j = i;
        while (1)
        {
            if ((j-1)/2<0)
                {break;}
            else if (t->data[(j-1)/2] < t->data[j])
            {
                tmp = t->data[j];
                t->data[j] = t->data[(j-1)/2];
                t->data[(j-1)/2] = tmp;
                j = (i-1)/2;
            }
            else
                {break;}
        }
    }
    }
}

void bfs(heap_t *t)
{
    int i;
    for (i=0;i<t->last_index;i++)
    {
        if (t->data[i] == -1)
            {break;}
        printf("%d ",t->data[i]);
    }
    printf("\n");
}

int main(void) { 
  heap_t *max_heap = NULL;
  int    m, n, i;
  int    command, data;
  int    old_key, new_key;

  scanf("%d %d", &m, &n);
  max_heap = init_heap(m);
  for (i=0; i<n; i++) {
    scanf("%d", &command);
    switch (command) {
      case 1:
        scanf("%d", &data);
        insert(max_heap, data);
        break;
      case 2:
        delete_max(max_heap);
        break;
      case 3:
        printf("%d\n", find_max(max_heap));
        break;
      case 4:
        scanf("%d %d", &old_key, &new_key);
        update_key(max_heap, old_key,
                   new_key);
        break;
      case 5:
        bfs(max_heap);
        break;

    }
  }
  return 0;
}