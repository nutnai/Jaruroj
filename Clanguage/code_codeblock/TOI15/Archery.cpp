#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    vector<int> high;
    int ru[n];
    int highest = 2e9;
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        high.push_back(x);
        highest = min(highest,x);
    }
    sort(high.begin(),high.end());
    int data[high+1][n+1];
    for(int i=0;i<n;i++){
        scanf("%d",&ru[i]);
    }
    for(auto h : high){
        if(h>highes){
            break;
        }

    }
}
