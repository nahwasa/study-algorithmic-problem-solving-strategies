#include<bits/stdc++.h>
using namespace std;
vector<int> pre_list, in_list;

void solve(int pre_s, int in_s, int in_e){
    if(in_s>in_e) return;
    int chk=pre_list[pre_s], i;
    for(i=in_s ; in_list[i]^pre_list[pre_s] ; i++);
    solve(pre_s+1,in_s,i-1);
    solve(pre_s+1+i-in_s,i+1,in_e);
    cout<<chk<<' ';
}

int main(){
    cin.tie(0);
    int c; cin>>c;
    while(c--){
        pre_list.clear();
        in_list.clear();
        
        int n; cin>>n;
        for(int i=0 ; i<n ; i++){
            int a; cin>>a;
            pre_list.push_back(a);
        }
        for(int i=0 ; i<n ; i++){
            int a; cin>>a;
            in_list.push_back(a);
        }
        
        solve(0,0,n-1);
        cout<<'\n';
    }
}
