#include<bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;
using tiii = tuple<int,int,int>;

priority_queue<tiii,vector<tiii>,greater<tiii>> jud;
vector<pii> graf[10001];
int ans[10001];
bool visit[10001];
int st,fn,node,link,bpm;

void kit(int w,int now,int kaow) {
    visit[now]=true;
    jud.pop();
    int rob=graf[now].size();
    for(int i=0; i<rob; i++) {
        int chee=graf[now][i].first;
        int w=graf[now][i].second;
        if(!visit[chee]) {
            if(ans[chee]>ans[now]+w) {
                ans[chee]=ans[now]+w;
            }
            jud.push(make_tuple(ans[chee],chee,kaow+1));
        }
    }
    if(!jud.empty())
        kit(get<0>(jud.top()),get<1>(jud.top()),get<2>(jud.top()));
}

int main() {
    scanf("%d%d%d",&node,&link,&bpm);
    scanf("%d%d",&st,&fn);

    for(int i=1; i<=link; i++) {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        graf[x].push_back({y,z});
        ans[i]=2e9;
        visit[i]=false;
    }
    ans[st]=0;


    jud.push(make_tuple(0,st,1));
    kit(get<0>(jud.top()),get<1>(jud.top()),get<2>(jud.top()));
    cout<<ans[fn];
}
