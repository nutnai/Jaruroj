#include <bits/stdc++.h>
using namespace std;

int main()
{
    list<char> keep;
    int ans=0,k=-1;
    string data;
    cin>>data;
    while(true){
        k++;
        if(k>=sizeof(data)){
            cout<<"\n"<<ans;
            return 0;
        }
        keep.push_back(data[k]);
        if(data[k]=='S'||data[k]=='s'){
                k++;
                keep.push_back(data[k]);
            if(data[k]=='I'||data[k]=='i'){
                k++;
                keep.push_back(data[k]);
                if(data[k]=='P'||data[k]=='p'){
                    k++;
                    keep.push_back(data[k]);
                    if(data[k]=='A'||data[k]=='a'){
                        ans++;
                        cout<<'"';
                        for(int i=0;i<4;i++){
                            cout<<keep.front();
                            keep.pop_front();
                        }
                        cout<<'"';
                        keep.clear();
                    }
                }
            }
            while(!keep.empty()){
            cout<<keep.front();
            keep.pop_front();
        }
        }
        while(!keep.empty()){
            cout<<keep.front();
            keep.pop_front();
        }

    }
}
