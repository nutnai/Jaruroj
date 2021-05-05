#include <bits/stdc++.h>
using namespace std;



int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    vector<pair<int,int>> data[n+3];
    for(int i=0;i<m;i++){
        int x,y,z;
        scanf("%d %d %d",&x,&y,&z);
        data[x].push_back({y,z});
        data[y].push_back({x,z});
    }
    
}