#include<bits/stdc++.h>
#include<sstream>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>v;
    string s;
    getline(cin,s);
    string temp="";
    for(int i=1;i<s.length();i++){
        if(s[i]==' '){
            stringstream ss(temp);
            int x=0;
            ss>>x;
            temp="";
            v.push_back(x);
        }
        else{
            temp+=s[i];
        }
    }
    stringstream ss(temp);
    int x=0;
    ss>>x;
    temp="";
    v.push_back(x);
    if(v.size()==n) cout<<"YES";
    else cout<<"NO";
    return 0;
}