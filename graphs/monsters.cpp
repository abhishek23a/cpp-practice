#include<bits/stdc++.h>
using namespace std;
//#define int long long int

int n,m;
vector<vector<int>>graph;
vector<pair<int,int>>monsters;
map<pair<int,int>,pair<int,int>>par;
vector<pair<int,int>>moves={{-1,0},{1,0},{0,1},{0,-1}};
pair<int,int>si,se;
bool isValid(int x, int y, int timer){
    if(x<0 || y<0 || x>=n || y>=m){
        return false;
    }
    if(graph[x][y]<=timer){
        return false;
    }
    return true;
}
bool valid_escape(int x,int y,int timer){
    if(!isValid(x,y,timer))return false;
    if(x==0 || y==0 || x==n-1 || y==m-1)return true;
    return false;
}
bool bfs_escape(){
    queue<pair<pair<int,int>,int>>q;
    q.push(make_pair(si,0));
    par[si]={-1,-1};
    while(!q.empty()){
        int cx=q.front().first.first;
        int cy=q.front().first.second;
        int timer=q.front().second;
        timer++;
        q.pop();
        for(auto mv:moves){
            int nx=cx+mv.first;
            int ny=cy+mv.second;
            if(valid_escape(nx,ny,timer)){
                par[{nx,ny}]={cx,cy};
                se={nx,ny};
                return true;
            }
            if(isValid(nx,ny,timer)){
                par[{nx,ny}]={cx,cy};
                graph[nx][ny]=timer;
                q.push({{nx,ny},timer});
            }
        }
    }
    return false;
}
void preprocess_mons(){
    queue<pair<pair<int,int>,int>>q;
    for(auto m:monsters){
        q.push(make_pair(m,0));
    }
    while(!q.empty()){
        int mx=q.front().first.first;
        int my=q.front().first.second;
        int timer=q.front().second;
        timer++;
        q.pop();
        for(auto mv:moves){
            int nx=mx+mv.first;
            int ny=my+mv.second;

            if(isValid(nx,ny,timer)){
                graph[nx][ny]=timer;
                q.push({{nx,ny},timer});
            }
        }
    }
}

int main(){
    cin>>n>>m;
    graph.resize(n);
    for(int i = 0; i < n; ++i){
        graph[i].resize(m);
    }
    for(int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            graph[i][j] = INT_MAX;
        }
    }  
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char c;
            cin>>c;
            if(c=='#'){
                graph[i][j]=0;
            }
            else if(c=='M'){
                graph[i][j]=0;
                monsters.push_back({i,j});
            }
            else if(c=='A'){
                graph[i][j]=0;
                si={i,j};
            }
            else{
                graph[i][j]=INT_MAX;
            }
        }
    }
    if(si.first==0 || si.second==0 || si.first==n-1 || si.second==m-1){
        cout<<"YES"<<endl;
        cout<<0;
        return 0;
    }
    preprocess_mons();
    if(!bfs_escape()){
        cout<<"NO";
        return 0;
    }
    cout<<"YES"<<endl;
    pair<int,int>tmp=se,tmp1=par[se],ed={-1,-1};
    vector<char>ans;
    while(tmp1 != ed){
        if((tmp.second - tmp1.second) == 1 and (tmp.first - tmp1.first) == 0){
            ans.push_back('R');
        }
        if((tmp.second - tmp1.second) == -1 and (tmp.first - tmp1.first) == 0){
            ans.push_back('L');
        }
        if((tmp.second - tmp1.second) == 0 and (tmp.first - tmp1.first) == 1){
            ans.push_back('D');
        }
        if((tmp.second - tmp1.second) == 0 and (tmp.first - tmp1.first) == -1){
            ans.push_back('U');
        }
        tmp = par[tmp];
        tmp1 = par[tmp];
    }
    reverse(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    for(auto x:ans)
        cout<<x;
}