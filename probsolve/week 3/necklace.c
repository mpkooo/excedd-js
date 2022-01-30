#include <iterator>
#include <list>
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i=1;i<=n;i++)
    {
        list<int> mylist[i];
        mylist[i].push_front(i);
    }
    for (int i=0;i<n-1;i++)
    {
        int x,y;
        cin >> x >> y;
        for (i=1;i<=n;i++)
        {
            for (list<int> :: iterator j=mylist[i].begin();j!=mylist[j].end();j++)
            {
                if (*j == y)
                    {break;}
            }
        }
        mylist[y].splice(*j,mylist[x]);
    }

    return 0;
}