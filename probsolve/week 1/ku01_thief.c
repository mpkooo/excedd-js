#include <stdio.h>

int main() {

    int n,k,t,i;
    scanf("%d %d %d",&n,&k,&t);
    int where=1,c=0;

    while(1)
    {
        c += 1;
        where += k;
        if (where>n)
            {where = where%n;}
        if (where==1)
            {break;}
        else if (where==t)
            {c += 1; break;}
    }
    printf("%d\n",c);
}