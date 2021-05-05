#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    scanf("%s",&s);
    list<char> ans;
    list<char>::iterator po;
    po=ans.begin();
    for(int i=1;i<=s.length();i++){
        switch(s.at(i-1)){
    case '[' :po=ans.begin();
            break;
    case ']' :po=ans.end();
            break;
    default :ans.insert(po,s.at(i-1));
        }
    }
    for(auto x:ans){
        cout<<x;
    }
}
