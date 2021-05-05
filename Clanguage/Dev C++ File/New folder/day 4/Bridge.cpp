#include<bits/stdc++.h>
using namespace std;

int mem[1001][1001];

int kit(int a[],int b[],int n) {
    mem[0][0]=0;
    mem[1][0]=0;
    mem[0][1]=0;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(a[i]==b[j])
                mem[i][j]=mem[i-1][j-1]+1;
            else
                mem[i][j]=max(mem[i-1][j],mem[i][j-1]);

        }
    }
    return mem[n][n];
}

int main() {
    int n;
    scanf("%d",&n);
    int a[n+1],b[n+1];
    for(int i=1; i<=n; i++) {
        scanf("%d",&a[i]);
    }
    for(int i=1; i<=n; i++) {
        scanf("%d",&b[i]);
    }
    cout<<kit(a,b,n);
}
