#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,k;
    string now,next;
    scanf("%d%d",&n,&k);
    cin>>now;

    for(int i=0; i<k-1; i++) {
        cin>>next;
        int c=0;
        for(int x=0; x<n; x++) {
            if(now[x]!=next[x]) {
                c++;
            }
        }
        if(c>2)
            break;
        else now=next;
    }
        cout<<now;
}
