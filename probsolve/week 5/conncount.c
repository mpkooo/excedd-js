#include <vector>
#include <list>
#include <iostream>
using namespace std;

const int maxnum = 100010;
vector<int> adj[maxnum];

int main()
{
    int n,m,i;
    cin >> n >>m;

    int deg[maxnum];

    for (i=0;i<n;i++)
        {deg[i] = 0;}

    for (i=0;i<m;i++)
    {   int u,v;
        cin >> u >> v; u-=1; v-=1;
        
        adj[u].push_back(v); adj[v].push_back(u);
        deg[u]+=1; deg[v]+=1;
    }

    int visited[maxnum],layer[maxnum];

    for (i=0;i<n;i++)
        {visited[i]=0; layer[i]=-1;}

    //bfs
    list<int> q;
    q.push_back(0);
    visited[0] = 1;
    layer[0] = 0;

    int ans=0,stop=0;
    while(stop==0)
    {
        while (!q.empty())
        {
            int tmp = q.front();
            q.pop_front();

            for (int i=0;i<deg[tmp];i++)
            {
                int node = adj[tmp][i];
                if (visited[node]!=1)
                {
                    q.push_back(node);
                    visited[node] = 1;
                    layer[node] = layer[tmp]+1;
                }
            }
        }
        ans += 1;

        stop=1;
        for (int i=0;i<n;i++)
        {   
            if (visited[i]==0)
            {
                stop = 0;
                q.push_back(i);
                visited[i] = 1;
                layer[i] = 0;
                break;
            }
        }
    }

    cout << ans << endl;
}