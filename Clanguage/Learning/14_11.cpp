#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    int h[n+3];
    int l[n+3];
    int ans[n+3];
    stack<pair<int,int>> st;
    for(int i=1;i<=n;i++){
        scanf("%d",&h[i]);
        while(!st.empty() && st.top().second <= h[i]){
                st.pop();
        }
        if(st.empty()){
            l[i]=1;
        }else{
            l[i]=st.top().first+1;
        }
        st.push({i,h[i]});
    }
    while(!st.empty()){
        st.pop();
    }
    for(int i=n;i>=1;i--){
        int r;
        while(!st.empty() && st.top().second <= h[i]){
                st.pop();
        }
        if(st.empty()){
            r=n;
        }else{
            r = st.top().first-1;
        }
        ans[i] = r-l[i]+1;
        st.push({i,h[i]});
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
}