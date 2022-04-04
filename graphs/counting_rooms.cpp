#include<bits/stdc++.h>
using namespace std;
char build[1001][1001];
bool vis[1001][1001];
int n, m;

bool verify(int x, int y){
    if(x<1 || x>n || y<1 || y>m)return false;
    if(vis[x][y]==true || build[x][y]=='#')return false;
    return true;
}

void dfs(int x,int y){
    vis[x][y]=true;
    if(verify(x-1,y)){
        dfs(x-1,y);
    }
    if(verify(x,y+1)){
        dfs(x,y+1);
    }
    if(verify(x+1,y)){
        dfs(x+1,y);
    }
    if(verify(x,y-1)){
        dfs(x,y-1);
    }
}

int main(){
    int count=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>build[i][j];
            vis[i][j]=false;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(build[i][j]=='.' && vis[i][j]==false){
                dfs(i,j);
                count++;
            }
        }
    }
    cout<<count<<endl;
    return 0;
}