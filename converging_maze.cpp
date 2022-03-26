#include<bits/stdc++.h>
using namespace std;
bool validCycle(vector<int> arr, int curr, vector<bool> &visited, vector<int> &path)
{
    if (curr == -1)
    {
        return false;
    }
    if (visited[curr])
    {
        return true;
    }
    visited[curr] = true;
    path.emplace_back(curr);
    if (validCycle(arr, arr[curr], visited, path))
        return true;
    return false;
}

int lSCycle(vector<int> arr,int n)
{   int sum = INT_MIN;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++)
    {
        visited[i] = true;

        vector<int> path;

        if (validCycle(arr, arr[i], visited, path))
            sum = max(sum, accumulate(path.begin(), path.end(), 0));

        visited[i] = false;
    }
    if (sum == INT_MIN)
        return -1;
    return sum;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>v;
        int temp;
        for(int i=0;i<n;i++){
            cin>>temp;
            v.push_back(temp);
        }
        cout<<lSCycle(v,n)<<endl;
    }
    return 0;
}