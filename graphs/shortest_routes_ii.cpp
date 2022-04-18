#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<vector<ll>>graph;
int N,M;
const int MAXD = 1e17;

ll dijkstra(int src,int dest){
    vector<ll>dist(N+1);
    for(int i=0;i<=N;i++){
        dist[i]=MAXD;
    }
    dist[src]=0;
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>pq;
    pq.push({0,src});
    while(!pq.empty()){
        ll w=pq.top().first;
        int u=pq.top().second;
        pq.pop();
        for(int v=1;v<=N;v++){
            if(graph[u][v]){
                if(dist[v]<=w+graph[u][v])continue;
                else{
                    dist[v]=graph[u][v]+w;
                    pq.push({dist[v],v});
                }
            }

        }
    }
    if(dist[dest]==INT_MAX)return -1;
    else return dist[dest];
}

int main(){
    ll q;
    cin>>N>>M>>q;
    graph.resize(N+1,vector<ll>(N+1,0));
    //dist.resize(N+1);
    //mark.resize(N+1);
    for(int i=0;i<M;i++){
        int a,b;
        ll w;
        cin>>a>>b>>w;
        if(graph[a][b]==0)
            graph[a][b]=graph[b][a]=w;
        else
            graph[a][b]=graph[b][a]=min(graph[a][b],w);
    }
    while(q--){
        int src,dest;
        cin>>src>>dest;
        ll measure=dijkstra(src,dest);
        cout<<measure<<endl;
    }
    return 0;

}