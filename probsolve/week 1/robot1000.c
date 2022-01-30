#include <stdio.h>
#include <string.h>

int main() {

    char w[1000];
    scanf("%s",&w);
    int x=0,y=0,i;
    int l = strlen(w);

    for (i=0;i<l;i++)
    {
        if (w[i]=='N')
            {y += 1;}
        else if (w[i]=='S')
            {y -= 1;}
        else if (w[i]=='E')
            {x += 1;}
        else if (w[i]=='W')
            {x -= 1;}
        else if (w[i]=='Z')
            {x=0; y=0;}
    }

    printf("%d %d\n",x,y);
}