#include<bits/stdc++.h>
using namespace std;
#define int long long int
vector<vector<int>>graph;
int n,m;
int inf=1e15;
int32_t main(){
    int q;
    cin>>n>>m>>q;
    graph.resize(n+1,vector<int>(n+1));
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            graph[i][j]=graph[j][i]=inf;
        }
    }
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        graph[a][b]=graph[b][a]=min(graph[a][b],c);
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                graph[i][j]=min(graph[i][j],graph[i][k]+graph[k][j]);
            }
        }
    }
    for(int i=0;i<q;i++){
        int u,v;
        cin>>u>>v;
        if(graph[u][v]==inf)cout<<-1<<endl;
        else cout<<graph[u][v]<<endl;
    }

}