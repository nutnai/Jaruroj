#include <bits/stdc++.h>
using namespace std;

int kormoon[1001][1001];
int maxx,maxy;

int rubka(int x,int y) {
    if(x<0||y<0||x>maxx||y>maxy)
        return 0;
    else
        return kormoon[x][y];
}

void tumkormoon() {
    for(int i=0; i<=maxx; i++) {
        for(int j=0; j<=maxy; j++) {
            kormoon[i][j]=kormoon[i][j]+rubka(i-1,j)+rubka(i,j-1)-rubka(i-1,j-1);
        }
    }

}

int main() {
    int rahut,rob;
    scanf("%d%d",&rahut,&rob);
    for(int i=1; i<=rahut; i++) {
        int x,y;
        scanf("%d%d",&x,&y);
        maxx=max(maxx,x);
        maxy=max(maxy,y);
        kormoon[x][y]++;
    }
    tumkormoon();
    for(int i=0;i<rob;i++){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        int x1=max(0,min(x-z,maxx));
        int x2=max(0,min(x+z,maxx));
        int y1=max(0,min(y-z,maxy));
        int y2=max(0,min(y+z,maxy));
        y=min(maxy,y);
        cout<<rubka(x2,y2)-rubka(x1-1,y2)-rubka(x2,y1-1)+rubka(x1-1,y1-1)<<"\n";
    }
}
