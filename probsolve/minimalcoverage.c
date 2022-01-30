#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n;
    cin >> n; cout << "\n";

    vector<pair<int,int>> ans[n];

    for (int i=0;i<n;i++)
    {
        vector<pair<int,int>> arr;

        int m,l,r;
        cin >> m;
        while(1)
        {
            cin >> l >> r;
            if (l==0 && r==0)
                {break;}
            arr.push_back(make_pair(r,l));
        }
        cout << "\n";
        //descending sort
        sort(arr.rbegin(), arr.rend());

        int start=0,tmp=0;
        while(1)
        {
            for (int j=0;j<arr.size();j++)
            {
                if (arr[j].second <= start)
                {
                    start = arr[j].first;
                    ans[i].push_back(make_pair(arr[j].second,arr[j].first));
                    if (arr[j].first >= m)
                        {tmp=2;}
                    arr.erase(arr.begin()+j); break;
                }
                else if (j==arr.size()-1)
                    {tmp=1; break;}
            }
            if (tmp==2 || tmp==1)
                {break;}
        }
        if (tmp==1)
            {ans[i].push_back(make_pair(0,0));}
    }

    for (int i=0;i<n;i++)
    {
        if (ans[i][ans[i].size()-1].first==0 && ans[i][ans[i].size()-1].second==0)
                {cout << 0 << "\n" << "\n"; continue;}

        else
        {
            cout << ans[i].size() << "\n";
            for (int j=0;j<ans[i].size();j++)
            {
                cout << ans[i][j].first << " " << ans[i][j].second << "\n"; 
            }
        }
    }
}