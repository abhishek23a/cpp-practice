#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    long long a=5,ans=0;
    while(a<=n){
        ans+=n/a;
        a=a*5;
    }
    cout<<ans<<endl;
    return 0;
}