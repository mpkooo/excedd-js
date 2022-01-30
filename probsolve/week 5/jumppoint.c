#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n,r,i,j;
    vector<vector<int>> tree;

    tree[0].push_back(0); tree[0].push_back(0);
    for (i=1;i<=n;i++)
    {
        int a,b;
        cin >> a >> b;
        tree[i].push_back(a);
        tree[i].push_back(b);
    }
    tree[n+1].push_back(100); tree[n+1].push_back(100);

    int visited[n+2];
    for (i=0;i<n+2;i++)
        {visited[i]=0;}
    visited[0] = 1;

    int x=tree[0][0],y=tree[0][1],ans=1000;
    while(1)
    {
        int c=0;
        for (i=0;i<n+2;i++)
        {
            int check = (tree[i][0]*tree[i][0])+(tree[i][1]*tree[i][1]);
            if (visited[i]!=1 && (tree[i][0]>x || tree[i][1]>y) && check<=(r*r) )
            {
                x = tree[i][0]; y = tree[i][1];
                c += 1;
            }
        }
    }
}