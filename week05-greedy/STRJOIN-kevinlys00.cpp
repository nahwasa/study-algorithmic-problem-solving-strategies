#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    int c; cin>>c;
    while(c--){
        int n; cin>>n;
        priority_queue<int> str_length;
        for(int i=0 ; i<n ; i++){
            int t; cin>>t;
            str_length.push(-t);
        }
        int ans=0;
        
        while(--n){
            int str1=str_length.top();
            str_length.pop();
            int str2=str_length.top();
            str_length.pop();
            ans-=str1+str2;
            str_length.push(str1+str2);
        }
        
        cout<<ans<<'\n';
    }
}
