#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a,b,ans;
    cin>>a>>b;
    int k=0;

    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());

    int stop=(a.size()>b.size()?b.size():a.size());
    for(int i=0;i<stop;i++){
        int x=a[i]+b[i]+k-96;
        if(x>=10){
            ans.push_back(x-10+48);
            k=1;
        }else{
            ans.push_back(x+48);
            k=0;
        }
    }
    if(a.size()!=b.size()){
        string c=(a.size()<b.size()?b:a);
        int s=a.size()+b.size()-c.size();
        for(int i=s;i<c.size();i++){
            int x=c[i]+k-48;
            if(x>=10){
                ans.push_back(x-10+48);
                k=1;
            }else{
                ans.push_back(x+48);
                k=0;
            }
        }
    }
    if(k==1)
        ans.push_back(49);
    reverse(ans.begin(),ans.end());
    cout<<ans;
}
