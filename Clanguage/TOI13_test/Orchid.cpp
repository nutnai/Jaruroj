#include <bits/stdc++.h>
using namespace std;

int table[1000003];

int main(){
    int n,x;
    scanf("%d",&n);
    vector<int> block;
    block.push_back(0);
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        int kit = upper_bound(block.begin(),block.end(),x)-block.begin();
        if(kit >= block.size()){
            block.push_back(x);
        }else{
            block[kit]=x;
        }
    }
    cout<< n - block.size() +1;

    return 0;
    }
