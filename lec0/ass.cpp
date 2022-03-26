#include<iostream>
#include<vector>
using namespace std;
#define ll long long int
int main(){
	ll n;
    cin>>n;
	ll prices=0;
    vector<ll>li(n),ri(n);
	for(ll i=0;i<n;i++){
        cin>>li[i]>>ri[i];
    }
	for(ll i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if((li[i]>=li[j]&&li[i]<=ri[j])||(ri[i]>=li[j]&&ri[i]<=ri[j])||(li[j]>=li[i]&&li[j]<=ri[i])||(ri[j]>=li[i]&&ri[j]<=ri[i]))
				prices++;
		}
	}
	cout<<prices<<endl;
	return 0;
}