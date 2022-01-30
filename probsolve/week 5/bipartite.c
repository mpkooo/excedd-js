#include <vector>
#include <list>
#include <iostream>
using namespace std;

int main()
{
    int k;
    cin >> k;

    for (int i=0;i<k;i++)
    {
        long n,m;
        cin >> n >> m;

        vector<int> adj[n];
        //assign 0
        int deg[n];
        for (int j=0;j<n;j++)
            {deg[j] = 0;}

        //insert node to array
        for (int j=0;j<m;j++)
        {
            int u,v;
            cin >> u >>v;
            u-=1; v-=1;
            adj[u].push_back(v); adj[v].push_back(u);
            deg[u]+=1; deg[v]+=1;
        }

        int visited[n],color[n],ans=1;
        for (int j=0;j<n;j++)
            {visited[j] = 0;}

        //dfs
        list<int> s;
        s.push_front(0);
        visited[0] = 1;
        int c = 1;
        color[0] = c;

        while (!s.empty())
        {
            if (c==1)
                {c=0;}
            else if (c==0)
                {c=1;}

            int tmp = s.front();
            s.pop_front();

            for (int i=0;i<deg[tmp];i++)
            {
                int node = adj[tmp][i];

                if (visited[node]!=1)
                {
                    s.push_front(node);
                    visited[node] = 1;
                    color[node] = c;
                }
                else
                {
                    if (color[node]==color[tmp])
                    {
                        //cout << "node:" << color[node] << " " << "tmp:" << color[tmp] << endl;
                        ans = 0;
                    }
                }
            }
            if (ans == 0)
                {break;}
            //cout << "pass";
        }
        if (ans == 0)
            {cout << "no" << endl;}
        else
            {cout << "yes" << endl;}
    }
}