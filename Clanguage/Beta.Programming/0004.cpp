#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    bool up = false,low = false;
    cin>>s;
    for(auto x:s)
    {
        if(x >= 'A' and x <= 'Z')
        {
            up = true;
        }
        else
        {
            low = true;
        }
        if(up and low)break;
    }
    if(up and low)
    {
        cout<<"Mix";
    }
    else if(up)
    {
        cout<<"All Capital Letter";
    }
    else cout<<"All Small Letter";
    return 0;
}