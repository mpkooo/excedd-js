#include <stdio.h>

int main() {
    int n,k,i;
    scanf("%d %d",&n,&k);
    int left=n;
    double t[n];
    for (i=0;i<n;i++)
        {scanf("%lf",&t[i]);}
    
    double min = 999999999;
    for (i=0;i<n;i++)
    {
        if (t[i]<min)
            {min = t[i];}
    }
    //printf("%d\n",min);
    for(i=0;i<n;i++)
    {
        if ((((t[i]*(k-1))-(min*(k-1)))>min) && (t[i]!=min))
            {left-=1;}
        //printf("t[i]=%d left=%d\n",t[i],left);
    }
    printf("%d\n",left);
}