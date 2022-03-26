#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin>>n;
    long long sum=n*(n+1)/2;
    if(sum%2==1){
        cout<<"NO"<<endl;
    }
    else{
        long long ans=sum/2;
        vector<long long>a,b;
        for(int i=n;i>=1;i--){
            if(i<=ans){
                a.push_back(i);
                ans-=i;
            }
            else 
                b.push_back(i);
        }
        cout<<"YES"<<endl;
        cout<<a.size()<<endl;
        for(auto x:a)
            cout<<x<<" ";
        cout<<endl;
        cout<<b.size()<<endl;
        for(auto x:b)
            cout<<x<<" ";
    }
    return 0;
}