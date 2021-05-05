#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int n;
    scanf("%lld",&n);
    long long int a=0,b=0,c=0,d=0;
    if(n>=10){
        d=n/10;
        n%=10;
    }
    if(n>=5){
        c=n/5;
        n%=5;
    }
    if(n>=2){
        b=n/2;
        n%=2;
    }
    a+=n;
    cout<<a+b+c+d<<"\n"<<a<<" "<<b<<" "<<c<<" "<<d;
}
