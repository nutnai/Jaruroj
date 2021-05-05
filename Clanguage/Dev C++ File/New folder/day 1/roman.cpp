#include <bits/stdc++.h>
using namespace std;

map<char,int> k;

int main() {

    int n;
    scanf("%d",&n);
    for(int x=1; x<=n; x++) {
        int i=x;
        if(i>=100) {
            k['c']+=i/100;
            i%=100;
        }

        if(i<40) {
            k['x']+=i/10;
            i%=10;
        } else if(i<50) {
            k['x']++;
            k['l']++;
            i%=10;
        } else if(i<90) {
            k['x']+=(i/10)-5;
            k['l']++;
            i%=10;
        }else{
            k['x']++;
            k['c']++;
            i%=10;
        }

        if(i<4) {
            k['i']+=i;
        } else if(i<5) {
            k['v']++;
            k['i']++;
        } else if(i<9) {
            k['v']++;
            k['i']+=i-5;
        }else{
            k['i']++;
            k['x']++;
        }
    }

    cout<<k['i']<<" "<<k['v']<<" "<<k['x']<<" "<<k['l']<<" "<<k['c'];
}
