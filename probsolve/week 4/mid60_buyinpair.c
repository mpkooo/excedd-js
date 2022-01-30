#include <iostream>
#include <vector>
using namespace std;

int main()
{
    long long n,a,b;
    cin >> n >> a >> b;

    vector<long long> myarr;
    for (long long i=0;i<n;i++)
    {
        long long p;
        cin >> p;
        myarr.push_back(p);
    }

    long long ans=0;
    for (long long i=0;i<n-1;i++)
    {
        for (long long j=i+1;j<n;j++)
        {
            if ((i!=j) && (myarr[i]+myarr[j] >= a) && (myarr[i]+myarr[j] <= b))
                {ans+=1;}
        }
    }

    cout << ans;
}