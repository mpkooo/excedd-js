#include <vector>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<pair<long,long>> sch;

int main()
{
    long n,i;
    cin >> n;
    for (i=0;i<n;i++)
    {
        long s,t;
        cin >> s >> t;
        sch.push_back(make_pair(t,s));
    }
    //sort
    sort(sch.begin(),sch.end());

    long end = sch[0].first, start = sch[0].second, ans=1;
    for (i=1;i<n;i++)
    {
        if (sch[i].second >= end)
            {end = sch[i].first; start = sch[i].second; ans+=1;}
    }

    cout << ans << '\n';
    /*
    cout << endl;
    for (i=0;i<n;i++)
        {cout << sch[i].first << ' ' << sch[i].second << endl;} */
}