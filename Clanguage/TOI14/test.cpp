#include <bits/stdc++.h>
using namespace std;

int main(){
    string a[2];
    for(int i=0;i<2;i++){
        cin>>a[i];
    }
    for(int i=0;i<2;i++){
        for(int j=0;j<a[i].size();j++){
            if(a[i][j]-48){
                cout<<"Y";
            }else cout<<"N";
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
}