#include <bits/stdc++.h>
using namespace std;

int ans=1,mx=-2e9;



void gps(vector<pair<int,int>> minimap[],int now,int power,bool check[])
{
    while(!minimap[now].empty())
    {
        if(power>=get<1>(minimap[now].back()) &&
           !check[get<0>(minimap[now].back())])
        {
            check[now]=true;
            int temp=power;
            power-=get<1>(minimap[now].back());
            ans=get<0>(minimap[now].back());
            mx=max(mx,ans);
            minimap[now].pop_back();
            gps(minimap,ans,power,check);
            power=temp;
        }else
        minimap[now].pop_back();
    }
}

int main()
{
    int node,road,power;
    scanf("%d %d %d",&node,&road,&power);
    vector<pair<int,int>> minimap[node+1];
    bool check[node+1];

    for(int i=1; i<=road; i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        minimap[x].push_back(make_pair(y,z));
        minimap[y].push_back(make_pair(x,z));
    }
    gps(minimap,1,power,check);
    if(mx==-2e9)
        cout<<"1";
    else cout<<mx;
}
