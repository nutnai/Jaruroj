#include <bits/stdc++.h>
using namespace std;

int timee[1000000];

int main() {
    long long kon,sinka,mini=1000000;
    scanf("%lld%lld",&kon,&sinka);
    for(int i=1; i<=kon; i++) {
        int x;
        scanf("%d",&x);
        mini=(mini<x?mini:x);
        for(int j=x; j<1000000; j+=x)
            timee[j]++;
    }
    int now=mini,fn=0;
    while(true) {
        if(time[now]!=0) {
            int siz=timee[now];
            fn=now;
            sinka-=siz;
        }
        if(sinka<=0)
            break;
        now++;
    }
    cout<<fn;
    return 0;
}
