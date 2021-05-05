#include <bits/stdc++.h>
using namespace std;

int main(){
    int score=0;
    for(int i=1;i<=3;i++){
        int x;
        scanf("%d",&x);
        score+=x;
    }
    if(score<50)cout<<"F";else 
    if(score<55)cout<<"D";else 
    if(score<60)cout<<"D+";else
    if(score<65)cout<<"C";else
    if(score<70)cout<<"C+";else
    if(score<75)cout<<"B";else
    if(score<80)cout<<"B+";else
    cout<<"A";
    
    return 0;
}