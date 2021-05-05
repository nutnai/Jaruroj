#include <bits/stdc++.h>
using namespace std;

int n;
int laka[103];
int st,fn,oil;
int tanon;
bool kumnun = true;
int ans=2e9;
vector<pair<int,int>> muang[103];
bool visit[103][103];

void kit(int now,int o,int cost,bool vi[][103]){

    if(!vi[now][o]){
        vi[now][o] = true;
    }else return;
    
    if(now == fn && o == oil){
        ans = min(ans,cost);
        return;
    }

    //เติมน้ำมัน
    if(o != oil){
        for(int i=1;i<=oil-o;i++){
            int newcost = cost+(i*laka[now]);
            if(newcost > ans){
                return;
            }
            kit(now,o+i,newcost,vi);
        }
    }

    //ใช้บัตรกำนัน
    if(o != oil && kumnun){
        for(int i=1;i<=oil-o;i++){
            kumnun=false;
            kit(now,o+i,cost,vi);
            kumnun=true;
        }
    }

    //ไปเมืองข้างๆ
    if(o!=0){
        for(auto x : muang[now]){
            int next = x.first;
            int w = x.second;
            if(o>=w){
                kit(next,o-w,cost,vi);
            }
        }
    }
    return;
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&laka[i]);
    }
    scanf("%d %d %d %d",&st,&fn,&oil,&tanon);
    for(int i=0;i<tanon;i++){
        int a,b,w;
        scanf("%d %d %d",&a,&b,&w);
        muang[a].push_back({b,w});
        muang[b].push_back({a,w});
    }

    kit(st,0,0,visit);

    cout<<ans;
}