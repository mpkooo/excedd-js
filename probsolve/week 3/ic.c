#include <list>
#include <iterator>
#include <iostream>
#include <string>
using namespace std;

int main ()
{
    int m,tmp;
    cin >> m;
    list<int> mylist;

    for (int i=0;i<m;i++)
    {
        int num; string op;
        cin >> op;
        if ( (op == "lr" || op == "rr") && mylist.begin()==mylist.end() )
            {continue;}
        else if (op == "li")
        {
            cin >> num; 
            mylist.push_front(num);
        }
        else if (op == "ri")
        {   
            cin >> num;
            mylist.push_back(num);
        }
        else if (op == "lr")
        {
            tmp = mylist.front();
            mylist.pop_front();
            mylist.push_back(tmp);
        }
        else if (op == "rr")
        {
            tmp = mylist.back();
            mylist.pop_back();
            mylist.push_front(tmp);
        }
    }
    for (list<int> :: iterator i=mylist.begin();i!=mylist.end();i++)
        {cout << *i << endl;}
}