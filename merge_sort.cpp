#include<bits/stdc++.h>
using namespace std;

void merge(int arr[],int low,int mid,int high){
    int temp[high-low+1];
    int i=low,j=mid+1,k=0;
    while(i<=mid && j<=high){
        if(arr[i]<=arr[j]){
            temp[k]=arr[i];
            k++;
            i++;
        }
        else{
            temp[k]=arr[j];
            k++;
            j++;
        }
    }
    while(i<=mid){
        temp[k]=arr[i];
        k++;
        i++;
    }
    while(j<=high){
        temp[k]=arr[j];
        k++;
        j++;
    }
    for(int i=low;i<=high;i++){
        arr[i]=temp[i-low];
    }
}

void merge_sort(int arr[],int low,int high){
    if(low>=high)return;
    int mid=(low+high)/2;
    merge_sort(arr,low,mid);
    merge_sort(arr,mid+1,high);
    merge(arr,low,mid,high);
}
void print_array(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[10]={8,9,10,1,5,4,6,77,5,12};
    int n=sizeof(arr)/sizeof(arr[0]);
    merge_sort(arr,0,n-1);
    print_array(arr,n);
    return 0;
}