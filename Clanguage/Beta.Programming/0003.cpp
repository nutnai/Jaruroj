#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int graf[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int x;
            scanf("%d",&x);
            graf[i][j]=x;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int x;
            scanf("%d",&x);
            cout<<graf[i][j]+x<<" ";
        }
        cout<<"\n";
    }
}