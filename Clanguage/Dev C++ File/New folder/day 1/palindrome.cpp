#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s,t;
    cin>>s;
    int l=s.length();
    for(int i=0;i<=l;i++){
        if(s[i]>=97)
            s[i]-=32;
    }
    t=s;
    reverse(t.begin(),t.end());
    if(t==s){
        int a=(l%2==0? l/2:(l+1)/2);
        int stop=(l%2==0? a:a-1);
        for(int i=0;i<stop;i++){
            if(s[i]!=s[a+i]){
                cout<<"Palindrome";
                return 0;
            }
        }
    cout<<"Double Palindrome";
    }else
    cout<<"No";
}
