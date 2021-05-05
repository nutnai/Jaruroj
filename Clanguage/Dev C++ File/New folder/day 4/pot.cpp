#include <bits/stdc++.h>
using namespace std;

int ans,k;

void kit(int n,int jan,int rob,int check[],int c){
    check[rob]-=c;
    if(jan==n){
            if(check[rob]>0)
            ans++;
        return;
    }
    if(check[rob]>0)
    kit(n,jan+1,rob,check,1);
    else{
        kit(n,jan+1,rob+1,check,0);
        check[rob]=k-1;
    }

    if(jan!=n && check[rob]==k-1){
        kit(n,jan+1,rob+1,check,0);
    }

}

int main()
{
    int n;
    scanf("%d%d",&n,&k);
    int check[n+1];
    for(int i=0;i<=n;i++)
        check[i]=k-1;

    kit(n,1,1,check,0);
    cout<<ans;
}
