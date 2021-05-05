#include <bits/stdc++.h>
using namespace std;

int laka[3][19];
int n;

double kit(int lem,int n1,int n2,int laka1,int laka2){
    if(lem>n)
        return (laka1*(100-n1)/100.0)+(laka2*(100-n2)/100.0);

    return min(kit(lem+1,n1+1,n2,laka1+laka[1][lem],laka2)
               ,kit(lem+1,n1,n2+1,laka1,laka2+laka[2][lem]));
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=2;i++){
        for(int j=1;j<=n;j++){
           scanf("%d",&laka[i][j]);
        }
    }
    printf("%.2f",kit(1,0,0,0,0));
}
