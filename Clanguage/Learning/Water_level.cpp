#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    int ans[n+3];
    int h[n+3];
    for(int i=0;i<n;i++){
        scanf("%d",&h[i]);
    }
    int l=0;
    int r=1;
    while(r<n){
        while(h[l]>h[r]){
            r++;
        }
        
    }
}