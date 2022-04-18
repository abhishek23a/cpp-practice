#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<pair<int,int>>v{{15,17}, {20,25},{50,51},{52,60}};
    pair<int,int>B={1,63};
    vector<pair<int,int>>ans;
    bool flag=false;
    int si=-1,ei=-1;
    int track=INT_MAX;
    for(int i=0;i<v.size();i++){
        if(!flag &&(B.first>=v[i].first && B.first<=v[i].second)){
            flag=true;
            si=v[i].first;
            track=i;
        }
        else if(flag && (B.second>=v[i].first && B.second<=v[i].second)){
            ei=v[i].second;
            track=i+1;
            break;
        }
        else if(!flag){
            ans.push_back(v[i]);
        }

    }
    if(si!=-1 && ei!=-1){
        ans.push_back({si,ei});
        for(int i=track;i<v.size();i++){
            ans.push_back(v[i]);
        }
    }
    else if(si!=-1){
        for(int i=track;i<v.size();i++){
            if(B.first>=v[i-1].second && B.second<=v[i].first){
                ans.push_back(B);
            }
            ans.push_back(v[i]);
        }
    }
    if(v[v.size()-1].second<B.first){
        ans.push_back(B);
    }
    for(auto x:ans){
        cout<<x.first<<" "<<x.second<<endl;
    }
}