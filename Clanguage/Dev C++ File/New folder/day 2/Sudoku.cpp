#include <bits/stdc++.h>
using namespace std;

int kormooon[10][10];
bool checkline[10][10];
bool checktunk[10][10];
bool checkblock[10][10];

int checkin(int line,int i,int n){
    if(checkline[line][n]==true)
        return 0;
    if(checktunk[i][n]==true)
        return 0;

}

void line(int line){
    for(int i=1;i<=9;i++){
        if(kormooon[line][i]==0){
            for(int n=1;n<=9;n++){
                int x=checkin(line,i,n);
            }
        }
    }
}

int main() {
    for(int i=1; i<=9; i++) {
        for(int j=1; j<=9; j++) {
            int x;
            int block=1+j/3+((i/3)*3);
            scanf("%d",&x);
            checkline[i][x]=false;
            checktunk[j][x]=false;
            kormooon[i][j]=x;
            if(x!=0){
                checkline[i][x]=true;
                checktunk[j][x]=true;
            }

        }
    }
    //for(int i=1;i<=9;i++)
    //line(i);
}
