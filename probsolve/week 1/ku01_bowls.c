#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,i,max=0;
    cin >> n;
    int s[n];
    for (i=0;i<n;i++)
        {cin >> s[i];}

    int c[300];
    for (i=0;i<300;i++)
        {c[i] = 0;}

    for (i=0;i<n;i++)
        {c[s[i]] += 1;}

    for (i=0;i<300;i++)
    {
        if (c[i] > max)
            {max = c[i];}
    }
    printf("%d\n",max);
}