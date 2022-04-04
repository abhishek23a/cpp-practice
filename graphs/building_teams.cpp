#include<bits/stdc++.h>
using namespace std;
int N,M;
vector<vector<long int>>graph;
vector<int>ans;
vector<bool>vis;

bool dfs(int u,int col,int par){
    vis[u]=true;
    ans[u]=col;
    for(auto v:graph[u]){
        if(v==par)continue;
        if(ans[v]==0){
            if(!dfs(v,(ans[u]^3),u))
                return false;
        }
        if(ans[v]==ans[u])
            return false;
    }
    return true;
}
bool dfs_util(){
    for(int i=1;i<=N;i++){
        if(!vis[i]){
            if(!dfs(i,1,-1))
                return false;
        }
    }
    return true;
}

int main(){
    cin>>N>>M;
    graph.resize(N+1);
    ans.resize(N+1);
    vis.resize(N+1);
    for(int i=0;i<=N;i++){
        ans[i]=0;
    }
    for(int i=0;i<M;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    if(dfs_util()==true){
        for(int i=1;i<=N;i++){
            cout<<ans[i]<<" ";
        }
    }
    else{
        cout<<"IMPOSSIBLE"<<endl;
    }
}