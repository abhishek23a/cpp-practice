#include<bits/stdc++.h>
using namespace std;
int N,M;
int sv,ev;
vector<vector<int>>graph;
vector<int>visited;
vector<int>parent;
bool dfs(int u,int par){
    visited[u]=true;
    parent[u]=par;
    for(auto v:graph[u]){
        if(v==par)continue;
        if(visited[v]){
            sv=v;
            ev=u;
            return true;
        }
        if(!visited[v]){
            if(dfs(v,u))return true;
        }
    }
    return false;
}
bool complete(){
    for(int i=1;i<=N;i++){
            if(!visited[i]){
                if(dfs(i,-1))return true;
            }
    }
    return false;
}
int main(){
    cin>>N>>M;
    graph.resize(N+1);
    visited.resize(N+1);
    parent.resize(N+1);
    for(int i=0;i<M;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    if(!complete()){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    int tv=ev;
    vector<int>ans;
    ans.push_back(ev);
    while(tv!=sv){
        ans.push_back(parent[tv]);
        tv=parent[tv];
    }
    ans.push_back(ev);
    cout<<ans.size()<<endl;
    for(auto x:ans)
        cout<<x<<" ";
}