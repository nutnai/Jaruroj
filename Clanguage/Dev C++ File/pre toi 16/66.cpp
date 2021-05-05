#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;

int node,maxx=0;
int ans=0,ansb=2e9;
vector<pii> graf[100003];
bool check[100003];
priority_queue<int> p,ansa;

void kit(int now) {
    check[now]=true;
    int rob=graf[now].size();
    if(now==node) {
        if(p.top()>s) {
            ans-=p.top();
            ans+=s;
        }
        if(ansb>ans) {
            ansa=p;
            ansb=ans;
        }
        return;
    }
    sort(graf[now].begin(),graf[now].end());
    for(int i=0; i<rob; i++) {
        int chee=graf[now][i].first;
        int w=graf[now][i].second;
        if(!check[chee]) {
            p.push(w);
            ans+=w;
            kit(chee);
            p.pop();
            check[chee]=false;
            ans-=w;
        }
    }
}

int main() {
    int link,s,t;
    scanf("%d%d%d%d",&node,&link,&s,&t);
    for(int i=0; i<link; i++) {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        graf[x].push_back({y,z});
        graf[y].push_back({x,z});
        maxx=max(maxx,z);
    }
    kit(1);
    if(ansa.empty()||ansb==2e9) {
        cout<<"No Honey TT";
        return 0;
    }
    if(ansa.top()>s) {
        ansb-=ansa.top();
        ansb+=s;
    }
    if(ansb<=t) {
        cout<<"Happy Winnie the Pooh :3\n"<<ansb;
    } else
        cout<<"No Honey TT";
    return 0;

}
