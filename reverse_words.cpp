#include<bits/stdc++.h>
using namespace std;
string reverseWords(string s) {
        int n=s.length(),i=0;
        stack<string>st;
        string temp="";
        while(i<n){
            //cout<<s;
            while(s[i]!=' ' && i<n){
                temp+=s[i];
                i++;
                //cout<<temp;
            }
            cout<<temp;
            st.push(temp);
            temp="";
            i++;
        }
        st.push(temp);
        cout<<temp;
        while(!st.empty()){
            cout<<st.top()<<" ";
            st.pop();
        }
        return "xyz";
    }
    int main(){
        string x="the sky is pink";
        string y=reverseWords(x);
        return 0;
    }