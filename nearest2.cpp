#include<bits/stdc++.h>
using namespace std;

int solution(vector<int> arr, int src, int dest){
    map<int,int> A,B;
    int start = arr[src];
    int curr = 1;
    set<int> s; 
    for(auto &x: arr){
        s.insert(x);
    }
    while(A[start] == 0){
        A[start] = curr;
        curr++;
        start = arr[start];
        if(start == -1){
            break;
        }
    }
    start = arr[dest];
    while(B[start] == 0){
        B[start] = curr;
        curr++;
        start = arr[start];
        if(start == -1){
            break;
        }
    }
    vector<pair<int,int>> temp;
    for(auto &x: s){
        if(A[x] != 0 && B[x] != 0){
            pair<int,int> p = {A[x] + B[x], x};
            temp.push_back(p);
        }
    }
    sort(temp.begin(), temp.end());
    return temp[0].second;
}

int main(){
    int n; cin>>n;
    vector<int> v;
    for(int i = 0; i<n; i++){
        int a; cin>>a;
        v.push_back(a);
    }
    int a,b; cin>>a>>b;
    cout << (solution(v,a,b));
}