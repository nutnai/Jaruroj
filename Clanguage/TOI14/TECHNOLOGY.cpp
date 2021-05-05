#include <bits/stdc++.h>
using namespace std;

int n,k,t;
vector<int> graf[100003];
int check[10003];
int ka[100003];
bool go[10003];
vector<int> start;
int ans=-1;
int cc[10003];

void kit(int node,int time,vector<int> next,bool go[],int cc[]){
    cc[ka[node]]++;
    if(time==0 ){
        for(int i=1;i<=n;i++){
            if(cc[i]==check[i] && cc[i]!=0){
                ans=max(ans,i);
            }else{
                return;
            }
        }
    }
    for(auto x:graf[node]){
        next.push_back(x);
    }
    for(auto x:next){
        if(!go[x]){
            go[x]=true;
            kit(x,time-1,next,go,cc);
            cc[ka[x]]--;
            go[x]=false;
        }
    }
    return;
}

int main(){
    scanf("%d %d %d",&n,&k,&t);
    for(int i=1;i<=n;i++){
        int m;
        scanf("%d %d",&ka[i],&m);
        check[ka[i]]++;
        if(m==0){
            start.push_back(i);
        }
        for(int j=0;j<m;j++){
            int x;
            scanf("%d",&x);
            graf[x].push_back(i);
        }
    }
    
    for(auto x:start){
        vector<int> next;
        kit(x,t-1,next,go,cc);

    }
    
    cout<<ans;
}