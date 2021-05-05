#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;

priority_queue<tiii,vector<tiii>,greater<tiii>> pq;
vector<pii> porka;
vector<int> path;
int por[3003];
int npor[3003];

int checkpor(int x){
    while(por[x] != x){
        x = por[x];
    }
    return por[x];
}

void ruoam(int x,int y){
    int porx = checkpor(x);
    int pory = checkpor(y);
    if(npor[porx] > npor[pory]){
        por[y]=porx;
        npor[porx]++;
    }else{
        por[x]=pory;
        npor[pory]++;
    }
}

int main(){
    int b,e;
    scanf("%d %d",&b,&e);
    for(int i=0;i<b;i++){
        por[i]=i;
    }
    for(int i=0;i<e;i++){
        int x,y,l,q;
        scanf("%d %d %d %d",&x,&y,&l,&q);
        if(q){
            ruoam(x,y);
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

    while(!pq.empty()){
        int l = get<0>(pq.top());
        int x = get<1>(pq.top());
        int y = get<2>(pq.top());
        pq.pop();
        cout<<x<<" ? "<<y<<" ";
        cout<<checkpor(x)<<" "<<checkpor(y)<<"\n";
        if(checkpor(x) != checkpor(y)){
            path.push_back(l);
            ruoam(x,y);
        }
    }
    sort(path.begin(),path.end());
    for(auto x:path){
        cout<<x<<" ";
    }
    long long ans = 0;
    int chee = 0;
    for(int i = path.size()-1;i>=0;i--){
        //printf("%d > %d ?\n",path[i],porka[chee].second);
            while(path[i]>porka[chee].second){
                chee++;
            }
            cout<<porka[chee].first<<"+";
            ans += porka[chee].first;
    }
    cout<<ans;
}
