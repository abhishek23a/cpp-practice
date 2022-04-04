#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>graph;
int N,M;
vector<bool>visited;
vector<int>par;
void bfs(){
    visited[1]=true;
    queue<int>q;
    q.push(1);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int v:graph[u]){
            if(!visited[v]){
                visited[v]=true;
                par[v]=u;
                q.push(v);
            }
        }
    }
}
int main(){
    cin>>N>>M;
    graph.resize(N+1);
    visited.resize(N+1);
    par.resize(N+1);
    for(int i = 0; i<=N; ++i)
	{
		par[i] = -1;
	}
    for(int i=0;i<M;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    bfs();
    if(par[N]==-1){
        cout<<"IMPOSSIBLE"<<endl;
    }
    else{
        stack<int>st;
        int route=N;
        while(route!=-1){
            st.push(route);
            route=par[route];
        }
        cout<<st.size()<<endl;
        while(!st.empty()){
            cout<<st.top()<<" ";
            st.pop();
        }
    }
}


