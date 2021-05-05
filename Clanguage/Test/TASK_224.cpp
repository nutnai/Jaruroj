#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x,y;
    int maxx = -30000;
    int ansx,ansy;
    scanf("%d %d",&x,&y);
    for(int i=0;i<x;i++)
    {
        for(int j=0;j<y;j++)
        {
            int k;
            scanf("%d",&k);
            if(k > maxx)
            {
                maxx = k;
                ansx = j;
                ansy = i;
            }
        }
    }
    cout<<ansx<<" "<<ansy;    
}