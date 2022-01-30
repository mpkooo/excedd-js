#include <iostream>
#include <vector>
using namespace std;

int main()
{
    long n,q;
    cin >> n >> q;

    long min=100000000;
    vector<long> h;
    for (long i=0;i<n;i++)
    {
        long tmp;
        cin >> tmp;

        if (tmp < min)
            {min = tmp;}
        h.push_back(min);
    }
    
    vector<long> ans;
    for (long i=0;i<q;i++)
    {
        long t;
        cin >> t;

        if (t==1)
        {
            long j;
            cin >> j;

            ans.push_back(h[j-1]);
        }

        else if (t==2)
        {
            long k;
            cin >> k;
            int L = 0; int R = h.size()-1;
            int avg = (L+R)/2 ;
            while(1)
            {
                if (k>h[0])
                    {avg=-1; break;}

                if (L==R)
                    {break;}
                else if (avg==0 && k > h[avg] )
                    {break;}
                else if (avg==h.size() && k <= h[avg])
                    {break;}

                if (k > h[avg])
                {
                    R = avg-1;
                    avg = (L+R)/2 ;
                }
                else if (k <= h[avg] && k<=h[avg+1])
                {
                    L = avg+1;
                    avg = (L+R)/2 ;
                }
                else
                    {break;}
            }
            ans.push_back(avg+1);
        }
    }

    for (int i=0;i<q;i++)
        {cout << ans[i] << "\n";}
}