#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;


int main()
{
    int node,link,s,t;
    scanf("%d%d%d%d",&node,&link,&s,&t);
    vector<pii> graf[node+3];
    vector<int> q;
    int ka[node+3];
    int por[node+3][2];

    for(int i=0;i<link;i++){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        graf[x].push_back({y,z});
        graf[y].push_back({x,z});
    }
    for(int i=2;i<=node;i++){
        ka[i]=2e9;
    }
    int road[graf[ ]
    ka[1]=0;
    q.push_back(1);
    while(!q.empty()){
        int now=q.back();
        q.pop_back();
        if(now==node)
            continue;
        int rob=graf[now].size();
        for(int i=0;i<rob;i++){
            int chee=graf[now][i].first;
            int w=graf[now][i].second;
            if((ka[chee]>ka[now]+w || ka[chee]==0 )&& chee!=1){
                por[chee][0]=now;
                por[chee][1]=w;
                ka[chee]=ka[now]+w;
                q.push_back(chee);
            }
        }
    }
    priority_queue<int> pi;
    int ans=ka[node];
    int n=node;
    while(true){
        if(n==1)
            break;
        pi.push(por[n][1]);
        n=por[n][0];
    }
    if(pi.top()>s){
        ans-=pi.top();
        ans+=s;
    }
    if(ans<t){
        cout<<"Happy Winnie the Pooh :3\n"<<ans;
    }else cout<<"No Honey TT";
    return 0;
}
