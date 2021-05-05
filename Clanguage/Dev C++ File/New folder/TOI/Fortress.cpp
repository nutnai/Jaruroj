#include <bits/stdc++.h>
using namespace std;

int main()
{
    for(int k=1;k<=20;k++){
        int n,line,ans=0;
    scanf("%d%d",&n,&line);
    n/=2;
    for(int a=0;a<=n;a++){
        for(int b=0;b<=n-a;b++){
            for(int c=0;c<=n-(a+b);c++){
                int d=n-(a+b+c);
                    if(a+b+c==line && a+c+d==line){
                    ans++;
                }
            }
        }
    }
    cout<<ans<<"\n";
    }

}
