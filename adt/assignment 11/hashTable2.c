#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define  TEXTSIZE 21

typedef char* item_t;

typedef struct hash {
  item_t *table;
  int    size;
  int    hash_key;
} hash_t;

hash_t *init_hashtable(int m, int key) 
{
    int i;
    hash_t *hashtable = (hash_t *)malloc(sizeof(hash_t));
    hashtable->size = m;
    hashtable->hash_key = key;
    hashtable->table = (item_t *)malloc(sizeof(item_t)*hashtable->size);
    for (i=0;i<m;i++)
        {hashtable->table[i] = NULL;}
    return hashtable;
}

unsigned int tobehash(hash_t *hashtable, char *text)
{
    unsigned int hash_value = 0;
    int i=0;
    for (i=0;i<strlen(text);i++)
        { hash_value = (hashtable->hash_key)*(hash_value) + text[i]; }
    return hash_value % hashtable->size;
}

void *insert(hash_t *hashtable,char *text)
{
    char *item = (char *)malloc(sizeof(char)*TEXTSIZE);
    strcpy(item,text);
    unsigned int myindex = tobehash(hashtable,text);
    if (hashtable->table[myindex] == NULL)
        { hashtable->table[myindex] = item; }
    else
    {
        int i=0;
        unsigned int new_index = 0;
        while(1)
        {   
            new_index = ((myindex + (i+(i*i))/2) % hashtable->size);
            //printf("newindex = %d\n",new_index);
            if (new_index >= hashtable->size)
            {
                new_index = 0;
                myindex = 0;
            }
            if (hashtable->table[new_index] == NULL)
            {
                hashtable->table[new_index] = item;
                //printf("text = %s",hashtable->table[new_index]->text);
                break;
            }
            i += 1;
        }
    }
}

int search(hash_t *hashtable, char *text)
{
    int i=0,j=0;
    unsigned int myindex = tobehash(hashtable,text);
    //printf("search.myindex = %d\n",myindex);
    if (hashtable->table[myindex] == NULL)
        {return -1;}
    else
    {
        while (1)
        {
            //printf("%s\n",hashtable->table[myindex]);
            unsigned int new_index = ((myindex + (i+(i*i))/2) % hashtable->size);
            if (new_index >= hashtable->size)
                {new_index=0; myindex=0;}
            else if (hashtable->table[new_index] == NULL)
                {return -1;}
            if (strlen(hashtable->table[new_index]) == strlen(text))
            {
                int ans=1;
                for (j=0;j<strlen(text);j++)
                {
                    if (hashtable->table[new_index][j] != text[j])
                        {ans = 0; break;} 
                }
                if (ans==1)
                    {return new_index;}
            }
            i += 1;
            //printf("pass");
        }
    }
}

int main(void) {
  hash_t *hashtable = NULL;
  char   *text = NULL;
  int    m, n, i, hash_key;
  int    command;

  scanf("%d %d %d", &m, &n, &hash_key);
  hashtable = init_hashtable(m, hash_key);
  text = (char *)malloc(sizeof(char)*TEXTSIZE);

  for (i=0; i<n; i++) {
    scanf("%d %s", &command, text);
    switch (command) {
      case 1:
        insert(hashtable, text);
        break;
      case 2:
        printf("%d\n", search(hashtable, text));
        break;
      }
  }
  return 0;
}