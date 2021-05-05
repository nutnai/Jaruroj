#include <bits/stdc++.h>
using namespace std;

int data[10][10];
int n,check;

void downleft(int x,int y,int sx,int sy) {
    if(data[x+1][y-1]==0 || (x==sx-1&&y==sy+1) )
        return ;
    if(data[x+1][y-1]==n){
        data[x][y]=n;
        return downleft(x-1,y+1,sx,sy);
    }
    return downleft(x+1,y-1,sx,sy);
}
void left(int x,int y,int sx,int sy) {
    if(data[x][y-1]==0 || (x==sx&&y==sy+1) )
        return ;
    if(data[x][y-1]==n){
        data[x][y]=n;
        return left(x,y+1,sx,sy);
    }
    return left(x,y-1,sx,sy);
}
void upleft(int x,int y,int sx,int sy) {
    if(data[x-1][y-1]==0 || (x==sx+1&&y==sy+1))
        return ;
    if(data[x-1][y-1]==n){
        data[x][y]=n;
        return upleft(x+1,y+1,sx,sy);
    }
    return upleft(x-1,y-1,sx,sy);
}
void up(int x,int y,int sx,int sy) {
    if(data[x-1][y]==0 || (x==sx+1&&y==sy))
        return ;
    if(data[x-1][y]==n){
        data[x][y]=n;
        return up(x+1,y,sx,sy);
    }
    return up(x-1,y,sx,sy);
}
void upright(int x,int y,int sx,int sy) {
    if(data[x-1][y+1]==0 || (x==sx+1&&y==sy-1))
        return ;
    if(data[x-1][y+1]==n){
        data[x][y]=n;
        return upright(x+1,y-1,sx,sy);
    }
    return upright(x-1,y+1,sx,sy);
}
void right(int x,int y,int sx,int sy) {
    if(data[x][y+1]==0 || (x==sx&&y==sy-1))
        return ;
    if(data[x][y+1]==n){
        data[x][y]=n;
        return right(x,y-1,sx,sy);
    }
    return right(x,y+1,sx,sy);
}
void downright(int x,int y,int sx,int sy) {
    if(data[x+1][y+1]==0 || (x==sx-1&&y==sy-1))
        return ;
    if(data[x+1][y+1]==n){
        data[x][y]=n;
        return downright(x-1,y-1,sx,sy);
    }
    return downright(x+1,y+1,sx,sy);
}
void down(int x,int y,int sx,int sy) {
    if(data[x+1][y]==0 || (x==sx-1&&y==sy))
        return ;
    if(data[x+1][y]==n){
        data[x][y]=n;
        return down(x-1,y,sx,sy);
    }
    return down(x+1,y,sx,sy);
}
void print() {
    for(int i=1; i<=8; i++) {
        for(int j=1; j<=8; j++) {
            if(data[i][j]==1)
                cout<<"O";
            else if(data[i][j]==2)
                cout<<"X";
            else
                cout<< ".";
        }
        cout<<"\n";
    }
}

int main() {
    int k;
    char lin;
    int r,l;

    data[4][4]=1;
    data[5][5]=1;
    data[4][5]=2;
    data[5][4]=2;

    scanf("%d",&k);
    for(int i=1; i<=k/2; i++) {
        for(n=2; n>=1; n--) {
            scanf(" %c%d",&lin,&r);
            l=lin-'a'+1;
            if(data[r][l]!=0 ||r<1||r>8||l<1||l>8)
                continue;
            data[r][l]=n;
            up(r,l,r,l);
            upright(r,l,r,l);
            right(r,l,r,l);
            downright(r,l,r,l);
            down(r,l,r,l);
            downleft(r,l,r,l);
            left(r,l,r,l);
            upleft(r,l,r,l);
        }
    }
print();
}
