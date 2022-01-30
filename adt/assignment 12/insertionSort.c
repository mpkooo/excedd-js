#include <stdio.h>

int main() {
    int n,i,j;
    scanf("%d",&n);
    int input,num[n];

    for (i=0;i<n;i++)
    {
        scanf("%d",&input);
        num[i] = input;
    }

    int tmp;
    for (j=1;j<n;j++)
    {
        int k=j;
        while(k!=0)
        {
            if (num[k]<num[k-1])
            {
                tmp = num[k-1];
                num[k-1] = num[k];
                num[k] = tmp;
            }
            k -= 1;
        }
        for (i=0;i<n;i++)
            {printf("%d ",num[i]);}
        printf("\n");
    }

    return 0;
}