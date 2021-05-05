#include <bits/stdc++.h>
using namespace std;
struct Vert{
    int w;
    int end;
    int start;
    Vert(int w,int start,int end){
        this->w=w;
        this->start=start;
        this->end=end;
    }
};

struct Comp{
    bool operator()(Vert const&l1,Vert const&l2){
        return l1.w < l2.w;
    }
};


int parent[100010];
int find_parent(int u){
    if(parent[u]!=u){
        return parent[u] = find_parent(parent[u]);
    }
    return u;
}

void merge(int u,int v){
    v = find_parent(v);
    u = find_parent(u);
    if(u>v){
        parent[u] = u;
        parent[v] = u;
    }
    else{
        parent[u] = v;
        parent[v] = v;
    }
    return;
}

int main(){
    int st,en;
    int w;
    vector<Vert> mst;
    int VERT,EDGE;
    scanf("%d",&VERT);
    int a[VERT];
    for(int i=0;i<VERT;++i){
        scanf("%d",&a[i]);
        parent[i] =i;
    }
    scanf("%d",&EDGE);
    for(int i=0;i<EDGE;i++){
        scanf("%d%d",&st,&en);
        mst.push_back(Vert(a[st-1]+a[en-1],st-1,en-1));
    }
    int sum=0;
    sort(mst.begin(),mst.end(),Comp());
    for(auto x: mst){
        int u = find_parent(x.start),v = find_parent(x.end);
        if(u == v){
            continue;
        }
        merge(u,v);
        sum+=x.w;
    }
    printf("%d ",sum);
}
