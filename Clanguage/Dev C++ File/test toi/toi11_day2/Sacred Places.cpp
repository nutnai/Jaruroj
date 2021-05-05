#include <bits/stdc++.h>
using namespace std;
using pp=pair<int,pair<int,int>>;

int hapor(int por[],int x){
    while(por[x]!=x){
        x=por[x];
    }
    return x;
}

int main()
{
    int node,link,ans=0;
    scanf("%d%d",&node,&link);
    priority_queue<pp,vector<pp>> q;
    int por[node+1];
    int npor[node+1];
    for(int i=1;i<=node;i++){
        por[i]=i;
        npor[i]=1;
    }
    for(int i=0;i<link;i++){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        q.push({z,{x,y}});
    }
    int path=0;
    while(path<node-1){
        int from=q.top().second.first;
        int to=q.top().second.second;
        int m=q.top().first;
        q.pop();
        int porfrom=hapor(por,from);
        int porto=hapor(por,to);
        if(porfrom!=porto){
            ans+=m-1;
                path++;
            if(npor[from]>npor[to]){
                por[porto]=porfrom;
            }else{
                por[porfrom]=porto;
                if(npor[porfrom]==npor[porto]){
                    npor[porfrom]++;
                }
            }
        }
    }
    cout<<ans;
}
