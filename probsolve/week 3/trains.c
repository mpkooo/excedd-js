#include <iostream>
#include <list>
#include <iterator>
using namespace std;
const int maxnum = 100001;

int main ()
{
    list<int> t[maxnum];
    int m;
    cin >> m;
    for (int k=0;k<m;k++)
    {
        int i,j; char op;
        cin >> op >> i >> j;
        if (op == 'N')
            {t[j].push_back(i);}
        else if (op == 'M')
            {t[j].splice(t[j].end(), t[i]);}
    }
    for (int i=0;i<maxnum;i++)
    {
        for (list<int> :: iterator it=t[i].begin(); it!=t[i].end(); it++)
            {cout << *it << endl;}
    }
    return 0;
}