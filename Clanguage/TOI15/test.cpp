#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> a = {1,2,3,4,5};
    for(auto x:a){
        cout<<x;
    }
    cout<<endl;
    sort(a.begin(),a.end());
    for(auto x:a){
        cout<<x;
    }
}