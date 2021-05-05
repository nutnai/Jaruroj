#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int ans=0,check=0;

    for(int i=0;i<sizeof(s);i++){
        if(s[i]>=65 &&s[i]<=90){
            check++;
        }else{
            if(check>=2){
                ans+=2;
            }else
            if(check==1){
               ans++;
            }
            check =0;
        }
    }
    cout<<ans;
}
