#include <iostream>
#include <vector>
using namespace std;

vector<char> box[1000];
int ulx,uly,urx,ury,dlx,dly,drx,dry;

int main()
{
    int n,m,i,j;
    cin >> n >> m;

    for (i=0;i<n;i++)
    {
        for (j=0;j<m;j++)
        {
            char x;
            cin >> x;
            box[i].push_back(x);
        }
    }

    int stop=0;
    //mark start point
    for (i=0;i<n-1;i++)
    {
        for (j=0;j<m-1;j++)
        {
            if (box[i][j]=='.' && box[i][j+1]=='.' && box[i+1][j]=='.' && box[i+1][j+1]=='.')
            {
                ulx=i,uly=j,urx=i,ury=j+1,dlx=i+1,dly=j,drx=i+1,dry=j+1;
                box[ulx][uly]='x'; box[urx][ury]='x'; box[dlx][dly]='x'; box[drx][dry]='x';
                stop=1; break;
            }
        }
        if (stop==1)
            {break;}
    }
    
    int ans=0;
    while(1)
    {
        //printf("ulx=%d,uly=%d urx=%d,ury=%d dlx=%d,dly=%d drx=%d,dry=%d\n",ulx,uly,urx,ury,dlx,dly,drx,dry);
        
        //down
        if (box[dlx+1][dly]=='.' && box[drx+1][dry]=='.' && drx<n && dlx<n)
            { ulx=dlx, uly=dly, urx=drx, ury=dry, dlx=dlx+1, drx=drx+1; box[ulx][uly]='x'; box[urx][ury]='x'; box[dlx][dly]='x'; box[drx][dry]='x';}
        //right
        else if (box[urx][ury+1]=='.' && box[drx][dry+1]=='.' && ury<m && dry<m)
            { ulx=urx, uly=ury, dlx=drx, dly=dry, ury=ury+1, dry=dry+1; box[ulx][uly]='x'; box[urx][ury]='x'; box[dlx][dly]='x'; box[drx][dry]='x';}
        //left
        else if (box[ulx][uly-1]=='.' && box[dlx][dly-1]=='.' && dly>0 && uly>0)
            { urx=ulx, ury=uly, drx=dlx, dry=dly, uly=uly-1, dly=dly-1; box[ulx][uly]='x'; box[urx][ury]='x'; box[dlx][dly]='x'; box[drx][dry]='x';}
        else
        {
            //right
            if (box[urx][ury+1]=='x' && box[drx][dry+1]=='x' && ury<m && dry<m)
                {box[ulx][uly]='b'; box[urx][ury]='b'; box[dlx][dly]='b'; box[drx][dry]='b'; ulx=urx, uly=ury, dlx=drx, dly=dry, ury=ury+1, dry=dry+1;}
            //left
            else if (box[ulx][uly-1]=='x' && box[dlx][dly-1]=='x' && dly>0 && uly>0)
                {box[ulx][uly]='b'; box[urx][ury]='b'; box[dlx][dly]='b'; box[drx][dry]='b'; urx=ulx, ury=uly, drx=dlx, dry=dly, uly=uly-1, dly=dly-1;}
            //up
            else if (box[ulx-1][uly]=='x' && box[urx-1][dly]=='x' && ulx>=0 && urx>=0)
                {box[ulx][uly]='b'; box[urx][ury]='b'; box[dlx][dly]='b'; box[drx][dry]='b'; dlx=ulx, dly=uly, drx=urx, dry=ury, ulx=ulx-1, urx=urx-1;}
        }

        if (dlx==n-1 && drx==n-1)
            {ans = 1; break;}
        else if (box[dlx+1][dly]!='x' && box[drx+1][dry]!='x' && box[urx][ury+1]!='x' && box[drx][dry+1]!='x' && box[ulx][uly-1]!='x' && box[dlx][dly-1]!='x' && box[ulx-1][uly]!='x' && box[urx-1][dly]!='x')
        {
            stop=0;
            for (j=0;j<m;j++)
            {
                if (box[0][j]=='.' && box[0][j+1]=='.' && box[1][j]=='.' && box[1][j+1]=='.')
                {
                    ulx=0,uly=j,urx=0,ury=j+1,dlx=1,dly=j,drx=1,dry=j+1;
                    box[ulx][uly]='x'; box[urx][ury]='x'; box[dlx][dly]='x'; box[drx][dry]='x';
                    stop=1; break;
                }
            }
            //cout << "stop=" << stop << endl;       
            if (stop!=1)
                {break;}
        }
    }

    if (ans==1)
        {cout << "yes" << endl;}
    else if (ans==0)
        {cout << "no" << endl;}
}