#include<bits/stdc++.h>
using namespace std;

bool cmp(string a, string b){
    int asize=a.size(), bsize=b.size();
    int checker=max(2*asize, 2*bsize);
    
    for(int i=0;i<checker;i++){
        if(a[i%asize]!=b[i%bsize]) return a[i%asize]>b[i%bsize];
    }
    return a>b;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, mx=0; cin>>n>>m;
    vector<string> str(n);
    for(int i=0 ; i<n ; i++){
        cin>>str[i];
        mx=max(mx,stoi(str[i]));
    }
    
    string tt=to_string(mx);
    for(int i=n ; i<m ; i++) str.push_back(tt);
    sort(str.begin(),str.end(),cmp);
    
    for(int i=0 ; i<m ; i++) cout<<str[i];
}
