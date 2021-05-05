#include <bits/stdc++.h>
using namespace std;

vector<int> friends[100001];
map<int,int> key;
bool check[100001];
int ans;

void kit(int x,int g)
{
    while(!friends[x].empty())
    {
        int temp=friends[x].back();
        if(!check[friends[x].back()])
        {
            key[temp]=g;
            friends[x].pop_back();
            check[temp]=true;
            kit(temp,g);

        }
        else
            friends[x].pop_back();
    }
}

int main()
{
    int node,link,kumtam,g=0;
    scanf("%d%d",&node,&link);
    for(int i=0; i<link; i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        friends[x].push_back(y);
        friends[y].push_back(x);
    }
    for(int i=1; i<=node; i++)
        if(!check[i])
        {
            g++;
            key[i]=g;
            check[i]=true;
            kit(i,g);
        }

    scanf("%d",&kumtam);
    for(int i=0; i<kumtam; i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if(key[x]==key[y])
            cout<<"Yes"<<"\n";
        else cout<<"No"<<"\n";
    }

}
