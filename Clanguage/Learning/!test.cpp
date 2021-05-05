#include <bits/stdc++.h>
using namespace std;

int main(){
    
    set<pair<int,int>> s;
    s.insert({1,2});
    auto k = s.find({1,3});
    if(k!=s.end()){
        cout<<"Found !";
    }else cout<<"Not found";
}