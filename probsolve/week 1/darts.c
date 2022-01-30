#include <stdio.h>
#include <math.h>

int main() {
    int n,x,y,s=0,i;
    float r;
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
        scanf("%d %d",&x,&y);
        r = sqrt((x*x)+(y*y));
        if (r<=2.00)
            {s+=5;}
        else if (r<=4.00)
            {s+=4;}
        else if (r<=6.00)
            {s+=3;}
        else if (r<=8.00)
            {s+=2;}
        else if (r<=10.00)
            {s+=1;}
    }
    printf("%d\n",s);
}