#include <vector>
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> a; vector<int> b;
    for (int i=0;i<n*2;i++)
    {
        int ca;
        cin >> ca;
        a.push_back(ca);
    }
    for (int i=0;i<n*2;i++)
    {
        int cb;
        cin >> cb;
        b.push_back(cb);
    }

    //first round
    int win_a1=0; int win_a2=0; int win_b1=0; int win_b2=0;
    int whoa1=0; int whoa2=0; int whob1=0; int whob2=0;
    for (int i=0;i<n;i++)
    {
        if (a[i]>win_a1)
        {
            win_a1 = a[i]; whoa1=i+1;
            //printf("win_a1 = %d; whoa1 = %d\n",win_a1,whoa1);    
        }
        if (a[i+n]>win_a2)
        {
            win_a2 = a[i+n]; whoa2=i+n+1;
            //printf("win_a2 = %d; whoa2 = %d\n",win_a2,whoa2);   
        }
        if (b[i]>win_b1)
        {
            win_b1 = b[i]; whob1=(2*n)+i+1;
            //printf("win_b1 = %d; whob1 = %d\n",win_b1,whob1);
        }   
        if (b[i+n]>win_b2)
        {
            win_b2 = b[i+n]; whob2=(2*n)+i+n+1;
            //printf("win_b2 = %d; whob2 = %d\n",win_b2,whob2);   
        }
    }

    //second round
    int win_a,win_b,whoa,whob,la,lb;
    if (win_a1>win_a2)
        {win_a=win_a1; whoa=whoa1; la=whoa2;}
    else
        {win_a=win_a2; whoa=whoa2; la=whoa1;}

    if (win_b1>win_b2)
        {win_b=win_b1; whob=whob1; lb=whob2;}
    else
        {win_b=win_b2; whob=whob2; lb=whob1;}

    //final
    int fp,sp;
    if (win_a>win_b)
        {fp = whoa; sp = whob;}
    else
        {fp = whob; sp = whoa;}

    printf("%d %d %d %d",fp,sp,la,lb);
}