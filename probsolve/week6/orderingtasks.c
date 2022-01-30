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
    cin >> n >> m;

    for (int i=0;i<n;i++)
        {numdegree.push_back(0); visited.push_back(0);}

    for (int i=0;i<m;i++)
    {
        int u,v;
        cin >> u >> v; u-=1; v-=1;
        numdegree[v] += 1;
        degree[u].push_back(v);
    }
    //for 0
    int x,y;
    cin >> x >> y;

    int tmp;
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
                break;
            }
        }
    }

    for (int i=0;i<ans.size();i++)
        {cout << ans[i]+1 << " ";}
}