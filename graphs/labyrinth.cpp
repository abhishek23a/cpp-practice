#include<bits/stdc++.h>
using namespace std;
int N,M;
char arr[1001][1001], dir[1001][1001];
bool vis[1001][1001];
vector<char>path;

bool verify(int x, int y){
    if(x<1 || x>N || y<1 || y>M)return false;
    if(vis[x][y]==true || arr[x][y]=='#')return false;
    return true;
}
bool findPath(int x,int y){
    queue<pair<int,int>>q;
    q.push({x,y});
    vis[x][y]=true;
    while(!q.empty()){
        int xcor=q.front().first;
        int ycor=q.front().second;
        q.pop();
        if(arr[xcor][ycor]=='B'){
            while(true){
                path.push_back(dir[xcor][ycor]);
                if(path.back()=='L')ycor++;
                if(path.back()=='R')ycor--;
                if(path.back()=='U')xcor++;
                if(path.back()=='D')xcor--;

                if(xcor==x && ycor==y)break;
            }
            return true;
        }
        if(verify(xcor,ycor-1)){
            dir[xcor][ycor-1]='L';
            vis[xcor][ycor-1]=true;
            q.push({xcor,ycor-1});
        }
        if(verify(xcor,ycor+1)){
            dir[xcor][ycor+1]='R';
            vis[xcor][ycor+1]=true;
            q.push({xcor,ycor+1});
        }
        if(verify(xcor-1,ycor)){
            dir[xcor-1][ycor]='U';
            vis[xcor-1][ycor]=true;
            q.push({xcor-1,ycor});
        }
        if(verify(xcor+1,ycor)){
            dir[xcor+1][ycor]='D';
            vis[xcor+1][ycor]=true;
            q.push({xcor+1,ycor});
        }

    }
    return false;
}

int main(){
    int x,y;
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin>>arr[i][j];
            vis[i][j]=false;
            if(arr[i][j]=='A'){
                x=i;
                y=j;
            }
        }
    }
    if(findPath(x,y)==true){
        cout<<"YES"<<endl<<path.size()<<endl;
        while(path.size()>0)cout<<path.back(), path.pop_back();
    }
    else{
        cout<<"NO";
    }
    return 0;
}