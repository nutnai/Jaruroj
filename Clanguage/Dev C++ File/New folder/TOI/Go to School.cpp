#include <bits/stdc++.h>
using namespace std;

bool check[51][51];
int n,m,ans=0;

int kit(int,int);

int right(int x,int y){
    if(!check[x][y+1])
        kit(x,y+1);
    else return 0;
}

int up(int x,int y){
    if(!check[x+1][y])
        kit(x+1,y);
    else return 0;
}

int kit(int x,int y) {
    if(x==n && y==m)
        return 1;
    if(x==n)
        return right(x,y);
    if(y==m)
        return up(x,y);
    return right(x,y)+up(x,y);

}

int main() {

    scanf("%d%d",&n,&m);
    int hma;
    scanf("%d",&hma);
    for(int i=0; i<hma; i++) {
        int x,y;
        scanf("%d%d",&x,&y);
        check[x][y]=true;
    }
    cout<<kit(1,1);
}
