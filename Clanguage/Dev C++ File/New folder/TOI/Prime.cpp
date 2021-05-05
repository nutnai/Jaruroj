#include <bits/stdc++.h>
using namespace std;

int siplan = 10000000;
int ka[500001];
bool check[10000000];

int main() {
    int n;
    scanf("%d",&n);
    int k=1;
    memset(check,true,sizeof(check));
    for(int i=2; i<siplan; i++) {
        while(!check[i])
            i++;
        ka[k]=i;
        k++;
        if(k>n)
            break;
        for(int j=i*2; j<siplan; j+=i) {
            check[j]=false;
        }
    }
    cout<<ka[n];
}
