#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d",&n);
    int ka[n+1],ans[n+1],last=0;
    for(int i=1; i<=n; i++) {
        scanf("%d",&ka[i]);
        ans[i]=0;
    }
    int st,fn,chee=1,k=1;
    while(chee<=n) {
        st=fn=ka[chee];
        chee++;
        if(chee>n)
            break;
        bool check=false;
        while(fn<=ka[chee]) {
            fn=ka[chee];
            chee++;
            check=true;
            if(chee>n)
                break;
        }
        if(check)
            last+=fn-st;
    }
    cout<<last;
}
