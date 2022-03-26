#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin>>n;
    long long prev,temp,ans=0;
    cin>>prev;
    for(int i=1;i<n;i++){
        cin>>temp;
        if(temp<prev){
            ans+=prev-temp;
        }
        else prev=temp;
    }
    cout<<ans;
    return 0;
}