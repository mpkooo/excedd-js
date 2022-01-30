#include <vector>
#include <iostream>
#include <stdio.h>
using namespace std;

vector<char> st;
vector<char> w;
long count=0,i=0,j=0,k=0,check=0,tmp,stop=0;

int main()
{
    while(1)
    {
        char input_w;
        scanf("%c",&input_w);
        if (input_w=='\n')
            {break;}
        else
            {w.push_back(input_w);}
    }
    while(1)
    {
        char input_st;
        scanf("%c",&input_st);
        if (input_st=='\n')
            {break;}
        else
            {st.push_back(input_st);}
    }

    while(i<st.size())
    {
        tmp = 0;
        for (j=k;j<w.size();j++)
        {
            if (w[j]!=st[i+tmp])
                {check=0; break;}
            else if (j==w.size()-1)
                {check=1; break;}
            tmp += 1;

            if (i+tmp == st.size())
                {stop==1; break;}
        }
        if (stop==1)
            {break;}

        if (check==0 && tmp==0)
            {i += tmp+1; continue;}
        else if (check==1)
            {count += 1; i += tmp+1; k=0; continue;}
        else
            {k=j;}
    }

    cout << count;
/*
    for (int i=0;i<w.size();i++)
        {cout << w[i] << ' ';}
*/
}