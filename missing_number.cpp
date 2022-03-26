#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin>>n;
    long long sum=0,temp;
    for(int i=1;i<=n-1;i++){
        cin>>temp;
        sum+=temp;
    }
    long long ans=(n*(n+1))/2-sum;
    cout<<ans<<endl;
    return 0;
}