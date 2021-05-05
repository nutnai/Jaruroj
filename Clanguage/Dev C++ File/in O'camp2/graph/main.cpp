#include <bits/stdc++.h>
using namespace std;
//รวม
void add(vector<list<int>> &v,int a,int b){
    v[a].push_back(b);
    v[b].push_back(a);
}

void dfs(vector<list<int>> &v,int a){
    vector<bool> visited(v.size(),0);
    stack<int> q;
    visited[a]=true;
    q.push(a);
    while(!q.empty()){
        a=q.top();
        cout<<a<<" ";
        q.pop();
        for(auto x:v[a]){
            if(!visited[x]){
                visited[x]=true;
                q.push(x);
            }
        }
    }
}

bool hascycle(vector<list<int>> &v,vector<bool> &visited,int u,int center){
    visited[u]=true;
    for(auto x: v[u]){
        if(!visited[x]){
            if(hascycle(v,visited,x,u))
                return true;
        }
        else if(x!=center){
            return true;
        }
    }
    return false;
}

bool checkcycle(vector<list<int>> &v){
    vector<bool> visited(v.size(),0);
    for(int i=1;i<v.size();i++)
        if(!visited[i])
            if(hascycle(v,visited,i,-1))
                return true;
    return false;
}

bool findpath(vector<list<int>> &v,int x,int y){
    vector<bool> visited(v.size(),0);
    stack<int> q;
    visited=true;
    q.push(x);
    while(!q.empty()){
        x=q.top();
        if(x==y){
            cout<<"path found\n";
            return true;
        }
        q.pop();
        for(auto w:v[x]){
            if(!visited[w]){
                visited[w]=true;
                q.push(w);
            }
        }
    }
    cout<<"path not found\n";
    return false;
}

int main(){
    int n=3;
    vector<list<int>> v(n);

    add(v,0,1);
    add(v,1,2);
    add(v,2,0);
    dfs(v,2);

}
