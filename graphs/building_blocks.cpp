#include<bits/stdc++.h>
using namespace std;
int N,M;
vector<vector<int>>graph;
vector<bool>vis;
vector<int>ver;

void dfs(int i){
    vis[i]=true;
    for(auto x:graph[i]){
        if(!vis[x]){
            dfs(x);
        }
    }
}

int main(){
    cin>>N>>M;
    graph.resize(N+1);
    vis.resize(N+1);
    for(int i=0;i<M;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int con=0;
    for(int i=1;i<=N;i++){
        if(!vis[i]){
            con++;
            ver.push_back(i);
            dfs(i);
        }
    }
    cout<<con-1<<endl;
    if(con>1){
        int u=ver[0],v;
        for(int i=1;i<con;i++){
            v=ver[i];
            cout<<u<<" "<<v<<endl;
            u=v;
        }
    }
    return 0;

}