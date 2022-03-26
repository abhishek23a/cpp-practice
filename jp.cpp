#include<bits/stdc++.h>
using namespace std;
int changeAds(int base10){
	int ans=0,temp=1;
	while(base10>0){
		if(!(base10&1)){
			ans+=temp;
		}
		temp=temp*2;
        base10=base10>>1;
	}
	return ans;
}
int main(){
    int base10;
    cin>>base10;
    int ans=changeAds(base10);
    cout<<ans;
    return 0;
}