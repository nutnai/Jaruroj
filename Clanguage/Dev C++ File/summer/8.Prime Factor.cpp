#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int a[]={2,3,5,7,11,13,17,19,23,29,31,37};
    vector<int> ans;
    while(n!=1){
        for(int i=0;i<12;i++){
            if(n%a[i]==0){
                n/=a[i];
                ans.push_back(a[i]);
                break;
            }
        }
    }
    int rob=ans.size();
    for(int i=0;i<rob-1;i++){
        cout<<ans[i]<<"x";
    }
    cout<<ans.back()<<"\n1";
}
