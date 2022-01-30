#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define  TEXTSIZE 21

typedef struct item {
  char   *text;
  struct item *next;
} item_t;

typedef struct hash {
  item_t **table;
  int    size;
  int    hash_key;
} hash_t;

hash_t *init_hashtable(int m, int key) 
{
    int i;
    hash_t *hashtable = (hash_t *)malloc(sizeof(hash_t));
    hashtable->size = m;
    hashtable->hash_key = key;
    hashtable->table = (item_t **)malloc(sizeof(item_t)*hashtable->size);
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
    item_t *item = (item_t *)malloc(sizeof(item_t));
    item->text = (char *)malloc(sizeof(char)*TEXTSIZE);
    item->next = NULL;
    strcpy(item->text,text);
    unsigned int myindex = tobehash(hashtable,text);
    //printf("index = %d\n",myindex);
    if (hashtable->table[myindex] == NULL)
        { hashtable->table[myindex] = item;}
    else
    {
        item->next = hashtable->table[myindex];
        hashtable->table[myindex] = item;
    }
}

int search(hash_t *hashtable, char *text)
{
    unsigned int myindex = tobehash(hashtable,text);
    if (hashtable->table[myindex] == NULL)
        {return -1;}
    else 
    {
        item_t *tmp = hashtable->table[myindex];
        while (1)
        {
            if (tmp == NULL)
                {return -1;}
            //printf("%s,%s ",tmp->text,text);
            if (strlen(tmp->text) == strlen(text))
            {
                int i=0,ans=1;
                for (i=0;i<strlen(text);i++)
                {
                    //printf("%c,%c",tmp->text[i],text[i]);
                    if (tmp->text[i] != text[i])
                        {
                            ans = 0;
                            break;
                        }
                    else if (tmp->text[i] != text[i])
                        {break;}
                    else if (ans == 1)
                        {return myindex;}
                }
            }
            tmp = tmp->next;
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