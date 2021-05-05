#include <bits/stdc++.h>
using namespace std;

int main(){

    vector<int> p = {1,2,3,4,5,6,7};
    for(int i=0;i<5;i++){
        vector<int> t = p;
        t.erase(t.begin()+i);
        for(auto x:t)cout<<x<<" ";
        cout<<"\n";
    }
}
