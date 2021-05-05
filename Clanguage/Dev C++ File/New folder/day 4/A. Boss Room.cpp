#include <bits/stdc++.h>
using namespace std;

int graf[1001][1001];
int mem[1001][1001];
int n,m;

int kit(int x,int y,int hp) {
    hp-=graf[x][y];
    if(hp<0 || x==0 || y==0 || x>n || y>m)
        return 0;
    if(mem[x][y]!=-1)
        return mem[x][y];
    if(x==n)
        return hp;
    return mem[x][y]=max(max(kit(x+1,y-1,hp+500),kit(x+1,y,hp+500)),kit(x+1,y+1,hp+500));
}

int main() {
    int hp=5000,ans=0;
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            scanf("%d",&graf[i][j]);
            mem[i][j]=-1;
        }
    }
    for(int i=1; i<=m; i++) {
        ans=max(ans,kit(1,i,5000));
    }
    if(ans==0)
        cout<<"-1";
    else
        cout<<abs(ans-(n*500)-4500);
}
