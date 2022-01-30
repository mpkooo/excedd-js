#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *dosort(char w[50])
{
    char *new;
    new = (char *)malloc(sizeof(char)*50);
    strcpy(new,w);
    int i,j,k,tmp;
    for (j=1;j<strlen(new);j++)
    {
        int k=j;
        while(k!=0)
        {
            //printf("pass1");
            if (new[k]<new[k-1])
            {
                tmp = new[k-1];
                new[k-1] = new[k];
                new[k] = tmp;
            }
            k -= 1;
        }
    }
    return new;    
}

int main() {
int n,m,i,j,k,l;
scanf("%d %d",&n,&m);
char find_w[50];
char word_l[n][50], mylist[n][50], *sorted;
sorted = (char *)malloc(sizeof(char)*50);

for (i=0;i<n;i++)
{
    scanf("%s",&word_l[i]);
    sorted = dosort(word_l[i]);
    strcpy(mylist[i],sorted);
}
//printf("pass2");
for (j=0;j<m;j++)
{
    scanf("%s",&find_w);
    sorted = dosort(find_w);

    for (k=0;k<n;k++)
    {
        //printf("pass3");
        int ans = 1;
        if (strlen(sorted) == strlen(mylist[k]))
        {
            for (l=0;l<strlen(sorted);l++)
            {
                if (sorted[l]!=mylist[k][l])
                {
                    ans = 0;
                    break;
                }
            }
            if (ans == 1)
                {printf("%s ",word_l[k]);}
        }
    }
    printf("\n");
}
return 0;
}