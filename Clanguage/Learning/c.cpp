#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> g[10000];
int ka[10000];

void kit(int x,int y){
    for(auto a : g[x]){
        if(a==y)
            continue;
        kit(a,x);
        ka[x]=max(ka[x],ka[a]+1);
    }
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    kit(1,0);
    cout<<"answer is\n";
    for(int i=1;i<=n;i++){
        printf("%d\n",ka[i]);
    }
}