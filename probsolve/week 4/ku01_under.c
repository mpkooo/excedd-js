#include <vector>
#include <iostream>
using namespace std;

int main()
{
    int l,n;
    cin >> l >> n;
    vector<float> br;
    for (int i=0;i<n;i++)
    {
        float a,b;
        cin >> a >> b;
        float j=a+0.5;
        while(j<b)
        {
            //printf("j=%f\n",j);
            br.push_back(j);
            j += 0.5;
        }
    }
    vector<int> findans;
    float i=0;
    while(i<l)
    {
        int c=0;
        for (int j=0;j<br.size();j++)
        {
            //printf("%f ",br[j]);
            if (br[j]==i)
                {c += 1;}
        }
        findans.push_back(c);
        //printf("\n");
        i += 0.5;
    }
    int max=0;
    for (vector<int> :: iterator it=findans.begin(); it!=findans.end(); it++)
    {
        if (*it > max)
            {max = *it;}
    }
    printf("%d",max);
}