#include <bits/stdc++.h>
using namespace std;

int n,m;
int graf[103][103];
int mom;
int notmom;

void kit(int x,int y){
    if(x==0 || y==0 || x>n || y>m){
        return;
    }
    if(graf[x][y]==notmom){
        graf[x][y]=mom;
        kit(x+1,y);
        kit(x-1,y);
        kit(x,y+1);
        kit(x,y-1);
    }
}

int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&graf[i][j]);
        }
    }
    int x,y,z;
    scanf("%d %d %d",&x,&y,&mom);
    notmom = graf[x][y];
    if(mom != notmom){
        kit(x,y);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<graf[i][j]<<" ";
        }
        cout<<"\n";
    }
}