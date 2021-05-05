#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num1,num2,maxximum;
    scanf("%d%d",&num1,&num2);
    /*num1<=num2?maxximum=num1:maxximum=num2;
    if(maxximum==0){
        cout<<num1+num2;
        return 0;
    }
    for(int i=maxximum;i>=0;i--){
        if(num1%i==0 && num2%i==0){
            cout<<i;
            return 0;
        }
    }*/

    cout<<__gcd(num1,num2);


}
