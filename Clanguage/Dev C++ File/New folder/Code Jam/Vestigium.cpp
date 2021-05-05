#include <bits/stdc++.h>
using namespace std;

int main(){
    int t,n;
    scanf("%d",&t);

    for(int nt=1;nt<=t;nt++){
        scanf("%d",&n);
        int k=0,r=0,c=0,pp=1;
        bool checknon [n+1];
        bool checktuank[n+1][n+1];

        for(int i=1;i<=n;i++){

            for(int j=1;j<=n;j++){
                checknon[j]=false;
                if(pp==1){
                    for(int z=0;z<=n;z++){
                        checktuank[j][z]=false;
                    }
                }
            }
            pp=2;
            int m=0;
            for(int j=1;j<=n;j++){
                int x;
                scanf("%d",&x);
                if(i==j){
                    k+=x;
                }
                if(!checknon[x]){
                    checknon[x]=true;
                }else m=1;

                if(!checktuank[j][x]){
                    checktuank[j][x]=true;
                }else checktuank[j][0]=true;
            }
            r+=m;
        }

        for(int i=1;i<=n;i++){
            if(checktuank[i][0]==true){
                c++;
            }
        }
        cout<<"Case #"<<nt<<": "<<k<<" "<<r<<" "<<c<<"\n";
    }
}
