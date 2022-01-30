#include <list>
#include <iostream>
#include <iterator>
using namespace std;

int main()
{
    list<int> mylist;
    int m;
    cin >> m;
    for (int i=0;i<m;i++)
    {
        int x;
        char op;
        cin >> op >> x;
        if (op == 'I')
            {mylist.push_front(x);}
        else if (op == 'A')
            {mylist.push_back(x);}
        else if (op == 'D')
        {
            int c=0;
            for (list<int> :: iterator i=mylist.begin();i!=mylist.end();++i)
            {
                if (c+1 == x)
                    {mylist.erase(i); break;}
                c += 1;
            }
        }
    }
    for (list<int> :: iterator i=mylist.begin();i!=mylist.end();++i)
        {cout << *i << endl;}

    return 0;
}