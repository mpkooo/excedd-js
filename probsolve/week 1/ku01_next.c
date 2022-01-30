#include <stdio.h>

int main ()
{
    int n,i;
    scanf("%d",&n);
    int a[n],num[n],c=0,round=1,s[n];
    for (i=0;i<n;i++)
    {
        c += 1;
        scanf("%d",&a[i]);
        num[i] = c; s[i] = c;
    }
    
    int tmp[n];
    while(1)
    {   
        int end=1;
        for (i=0;i<n;i++)
        {   tmp[i] = s[i]; 
            //printf("tmp = %d /",tmp[i]);
        }

        for (i=0;i<n;i++)
            {s[a[i]-1] = tmp[i];}

        for (i=0;i<n;i++)
        {
            if (s[i]==num[i])
                {num[i] = 0;}
        
            if (num[i]!=0)
                {end = 0;}
        }
        if (end==1)
            {break;}
        round += 1;
    }
    printf("%d\n",round);
}