#include <bits/stdc++.h>
using namespace std;

 

int n,m;

int sq,di,tr;
string graf[10003];

void paint(int i,int j){
    if(i<1 || j<1 || i>=n || j>m){
        return;
    }else if(!(graf[i][j]-48)){
        return;
    }else graf[i][j] = 48;

    paint(i+1,j);
    paint(i-1,j);
    paint(i,j+1);
    paint(i,j-1);
}

void vikor(int i,int j){
    bool right = graf[i][j+1]-48;
    bool down = graf[i+1][j]-48;
    bool downleft = graf[i+1][j-1]-48;
    bool downright = graf[i+1][j+1]-48;
    //สี่เหลี่ยม
    if(down && right){
        sq++;
    }else if(downleft && downright){
        //เพชร
        int i2=i,j2=j;
        while(graf[i2][j2]-48){
            i2++;
            if(i2 == n)break;
        }
        if(!(graf[i2-1][j2-1]-48) && !(graf[i2-1][j2+1]-48)){
            di++;
        }else{
            //สามเหลี่ยม
            tr++;
        }
    }else tr++;

    paint(i,j);

}

int main(){
    scanf("%d %d",&m,&n);
    for(int i=0;i<n;i++){
        cin>>graf[i];
        graf[i]="0"+graf[i]+"0";
    }
    for(int i=0;i<n;i++){
        for(int j=1;j<=m;j++){
            if(graf[i][j]-48){
                vikor(i,j);
            }
        }
    }
    cout<<sq<<" "<<di<<" "<<tr;
}