#include <vector>
#include <iostream>
#include <stdio.h>
using namespace std;

vector<int> numdegree;
vector<int> degree[100000];
vector<int> ans;
vector<int> visited;

int main()
{
    int n,m;
    scanf("%d",&n); scanf("%d",&m);

    for (int i=0;i<n;i++)
        {numdegree.push_back(0); visited.push_back(0);}

    for (int i=0;i<m;i++)
    {
        int u,v;
        scanf("%d",&u); scanf("%d",&v); u-=1; v-=1;
        numdegree[v] += 1;
        degree[u].push_back(v);
    }

    int stop=0,tmp;
    while(ans.size() != n)
    {
        for (int i=0;i<n;i++)
        {
            if (numdegree[i]==0 && visited[i]==0)
            {
                ans.push_back(i);
                visited[i] = 1;
                for (int j=0;j<degree[i].size();j++)
                {
                    tmp = degree[i][j];
                    numdegree[tmp] -= 1;
                }
                stop = 1;
                break;
            }
        }

        if (stop==0)
            {break;}
    }

    if (stop==0)
        {cout << "no";}
    else
    {
        for (int i=0;i<ans.size();i++)
            {cout << ans[i]+1 << "\n";}
    }
}