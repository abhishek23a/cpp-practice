#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int maxi=1,count=1;
    for(int i=1;i<s.length();i++){
        if(s[i]==s[i-1]){
            count++;
            maxi=max(maxi,count);
        }
        else count=1;
    }
    cout<<maxi;
    return 0;
}