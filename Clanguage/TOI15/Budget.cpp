#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;

vector<int> graf[3003];
priority_queue<tiii,vector<tiii>,greater<tiii>> pq;
vector<pii> porka,porkatemp;
vector<int> path;
bool visited[3003];

bool checkcycle(int x,int y,bool pai[]){
    vector<int> go = {x};
    while(!go.empty()){
        int now = go.back();
        if(pai[now]){
            return true;
        }
        go.pop_back();
        pai[now] = true;
        for(auto a:graf[now]){
            if(!pai[a]){
                go.push_back(a);
            }
        }
    }
    return false;
}

int har(int Long,int p){
    for(auto x:porka){
        if(Long<=x.second){
            return x.second;
        }
    }
    return;
}

int main(){
    int b,e;
    scanf("%d %d",&b,&e);
    for(int i=0;i<e;i++){
        int x,y,l,q;
        scanf("%d %d %d %d",&x,&y,&l,&q);
        if(q){
            graf[x].push_back(y);
            graf[y].push_back(x);
        }else{
            pq.push({l,x,y});
        }
    }
    int p;
    scanf("%d",&p);
    for(int i=0;i<p;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        porka.push_back({y,x});
    }
    sort(porka.begin(),porka.end());
    auto pointer = porka.end()-1;
    while(pointer != porka.begin()){
        auto pointerc = pointer;
        int before = pointerc-porka.begin()-1;
        int now = pointerc-porka.begin();
        while(pointerc !=porka.begin() && porka[before].first <= porka[now].first && porka[before].second >= porka[now].second){
            porka.erase(before+porka.begin());
            pointerc--;
            before = pointerc-porka.begin()-1;
            now = pointerc-porka.begin();
        }
        pointer--;
    }
    for(auto a:porka){
        porkatemp.push_back({a.second,a.first});
    }
    porka = porkatemp;
    while(!pq.empty()){
        int l = get<0>(pq.top());
        int x = get<1>(pq.top());
        int y = get<2>(pq.top());
        pq.pop();
        if(!checkcycle(x,y,visited)){
            path.push_back(l);
            graf[x].push_back(y);
            graf[y].push_back(x);
        }   
    }
    long long ans = 0;

    for(auto x:path){
        int cost = har(x,p);
        ans+=cost;
    }
    cout<<ans;
}