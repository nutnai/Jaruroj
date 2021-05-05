#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

int main(){
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    vector<pair<int,int>> graf[n+3];
    int Long[n+3];
    bool pai[n+3];
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    int ans = 0;

    for(int i=0;i<m;i++){
        int x,y,z;
        scanf("%d %d %d",&x,&y,&z);
        graf[x].push_back({y,z});
        graf[y].push_back({x,z});
    }

    for(int i=1;i<=n;i++){
        Long[i] = INT_MAX;
        pai[i] = false;
    }
    Long[1] = 0;
    pq.push({1,k});

    while(!pq.empty()){
        int now = pq.top().first;
        int pow = pq.top().second;
        ans = max(ans,now);
        pq.pop();
        if(pai[now]){
            continue;
        }else pai[now] = true;

        for(auto x:graf[now]){
            int go = x.first;
            int dis = x.second;
            if(Long[go] > Long[now] + dis && pow - dis >=0){
                Long[go] = Long[now] + dis;
                pq.push({go,pow - dis});
            }
        }
    }
    cout<<ans;
}   