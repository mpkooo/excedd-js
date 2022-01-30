#include <stdio.h>

int main() {
    int n,i,j,k,ans=0;
    scanf("%d",&n);
    int m[n],value[1000];

    for (i=0;i<n;i++)
        {scanf("%d",&m[i]);}

    for (j=0;j<n;j++)
    {
        if (m[j]>0)
            {ans += m[j];}
    }
    printf("%d\n",ans);
}