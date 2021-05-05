#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
typedef tuple<long long,int,int> tlii;

int main(){
    int n,m,t,st,fn;
    scanf("%d %d %d %d %d",&n,&m,&t,&st,&fn);
    vector<pii> graf[n+3];
    long long Long[n+3][10];
    bool pai[n+3][10];
    priority_queue<tlii,vector<tlii>,greater<tlii>> pq;

    for(int i=0;i<m;i++){
        int x,y,z;
        scanf("%d %d %d",&x,&y,&z);
        graf[x].push_back({y,z});
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<10;j++){
            pai[i][j] = false;
            Long[i][j] = LONG_LONG_MAX;
        }
    }
    Long[st][1%t] = 0;
    pq.push({Long[st][1%t],st,1%t});
    while(!pq.empty()){
        long long l = get<0>(pq.top());
        int now = get<1>(pq.top());
        int junkva = get<2>(pq.top());
        pq.pop();
        if(pai[now][junkva]){
            continue;
        }else pai[now][junkva] = true;

        if(now == fn && junkva % t == 0){
            cout<<Long[fn][0];
            return 0;
        }
        int junkvanext = (junkva+1)%t;
        for(auto x:graf[now]){
            int next = x.first;
            int w = x.second;
            if(Long[next][junkvanext] > l + w){
                Long[next][junkvanext] = l + w;
                pq.push({Long[next][junkvanext],next,junkvanext});
            }
        }
    }
    if(Long[fn][0] == LONG_LONG_MAX){
        cout<<"-1";
    }else cout<<Long[fn][0];
}