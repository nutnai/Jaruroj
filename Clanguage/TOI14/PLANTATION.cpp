#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){

        int tree,r,p;   
        bool cor = true;
        scanf("%d %d %d",&tree,&r,&p);
        int data[n+3][tree+3][2];
        for(int j=0;j<tree;j++){
            int x,y;
            scanf("%d %d",&x,&y);
            data[i][j][0]=x;
            data[i][j][1]=y;
            if(cor){
                for(int k=0;k<j;k++){
                    double kitx = pow(data[i][k][0]-(double)x,2);
                    double kity = pow(data[i][k][1]-(double)y,2);
                    double kit2 = pow(kitx+kity,0.5);
                    if(kit2 - (r*2) < p){
                        cor = false;
                        break;
                    }
                }
            }
        }
        if(cor){
            cout<<"Y\n";
        }else{
            cout<<"N\n";
        }
    }
}