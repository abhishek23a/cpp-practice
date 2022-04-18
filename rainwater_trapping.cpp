#include<bits/stdc++.h>
using namespace std;

int trap(int arr[],int n){
    int prefix[n],suffix[n];
    int left_max=INT_MIN,right_max=INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]>left_max){
            prefix[i]=arr[i];
            left_max=arr[i];
        }
        else{
            prefix[i]=left_max;
        }
    }
    for(int i=0;i<n;i++){
        cout<<prefix[i]<<" ";
    }//0 0 1 1 1 2 2 5
    cout<<endl;
    for(int i=n-1;i>=0;i--){
        if(arr[i]>right_max){
            suffix[i]=arr[i];
            right_max=arr[i];
        }
        else{
            suffix[i]=right_max;
        }
    }
    for(int i=0;i<n;i++){
        cout<<suffix[i]<<" ";
    }
    int ans=0;
    for(int i=1;i<n-1;i++){
        int temp=min(prefix[i],suffix[i]);
        if(arr[i]<temp){
            ans+=temp-arr[i];
        }
    }
    return ans;
}
int main(){
    int arr[]={1, 0, 0,2};
    int res=trap(arr,4);
    cout<<res;
    return 0;
}