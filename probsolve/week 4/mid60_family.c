#include <vector>
#include <iostream>
using namespace std;

int main()
{
    int n,m,c=0;
    cin >> n >> m;
    vector<int> tree;
    tree.push_back(0); tree.push_back(1);
    for (int i=2;i<=n;i++)
    {
        int tmp;
        cin >> tmp;
        tree.push_back(tmp);
    }
    vector<int> ans;
    for (int i=0;i<m;i++)
    {
        int x,y;
        cin >> x >> y;
        
        int index = x,anc=-1; 
        while(1)
        {
            if (tree[index]==y)
                {anc = y; break;}
            if (index==1)
                {break;}
            index = tree[index];
            //printf("index=%d\n",index);
            //printf("pass");
        }

        if (anc==-1)
        {
            index = y;
            while(1)
            {
                if (tree[index]==x)
                    {anc = x; break;}
                if (index==1)
                    {break;}
                index = tree[index];
            }
        }
        //printf("anc=%d\n",anc);
        ans.push_back(anc);
    }

    for (int i=0;i<m;i++)
        {printf("%d\n",ans[i]);}
}