#include <bits/stdc++.h>
using namespace std;
#define paa pair<int,int>
#define op max

vector<paa> vt[100];
int n,m,st,fn;
int ans,rea;

void kit(int now){
    if(fn==now){
        rea=op(rea,ans);
        return;
    }
    for(auto see:vt[now]){
        int next = see.first;
        int l = see.second;
        ans+=l;
        kit(next);
        ans-=l;
    }
    if(fn==now){
        rea=op(rea,ans);
    }
}

int main(){
    
    ans=op(0,2000000000);
    if(ans==0){
        ans=2000000;
    }else{
        ans=0;
    }
    rea=ans;
    ans=0;

    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        paa a={y,z};
        vt[x].push_back(a);
    }
    scanf("%d%d",&st,&fn);
    kit(st);
    cout<<"ans is "<<rea;
}

