#include <bits/stdc++.h>
using namespace std;

int main()
{
    int ndoor,tarm;
    scanf("%d%d",&ndoor,&tarm);
    int chee[ndoor+3];
    bool check[ndoor+3];
    vector<int> v;
    for(int i=1;i<=ndoor;i++){
        scanf("%d",&chee[i]);
        check[i]=false;
    }
    for(int i=0;i<tarm;i++){
        int phee,kon,salupa,salupb;
        scanf("%d%d%d%d",&phee,&kon,&salupa,&salupb);
        int temp=chee[salupa];
        chee[salupa]=chee[salupb];
        chee[salupb]=temp;
        while(true){
            if(phee==kon){
                cout<<"DEAD\n";
                while(!v.empty()){
                    check[v.back()]=false;
                    v.pop_back();
                }
                break;
            }
            if(check[phee]){
                cout<<"SURVIVE\n";
                while(!v.empty()){
                    check[v.back()]=false;
                    v.pop_back();
                }
                break;
            }
            check[phee]=true;
            v.push_back(phee);
            phee=chee[phee];
        }
        temp=chee[salupa];
        chee[salupa]=chee[salupb];
        chee[salupb]=temp;
    }
    return 0;
}
