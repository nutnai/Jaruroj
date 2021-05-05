#include <bits/stdc++.h>
using namespace std;
/*
int main()
{
    int count=0;
    for(int i=1;i<10000;i+=2){
        for(int j=3;j<i/2;j++){
            if(i%j==0){
                count=1;
                break;
            }
        }
        if(count==0){
            cout<<i<<" ";
        }
        if(i==1){
            cout<<"2"<<" ";
        }
        count=0;
    }
}
*/
const int arraySize = 1000000;
 Data[arraySize];
int Find;
int n;
int kit(int x)
{
    int l = 0;
    int r = n-1;
    int m;
    while(l <= r){
        m = (l+r)/2;
        if(Data[m] > x)
        {
            r = m - 1;
        }
        else if(Data[m] < x)
        {
            l = m + 1;
        }
        else
        {
            return Data[m];
        }
        
    }
    return 0;
}

int main()
{
    scanf("%d",&n);
    for(int i = 0 ; i < n ; i++)
    {
        scanf("%d",&Data[i]);
    }
    int q;
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        int x;
        scanf("%d",&x);
        int ans = kit(x);
        if(ans)
        {
            cout<<ans<<"\n";
        }
        else
        {
            cout<<"Not found\n";
        }
        
    }
}