#include<bits/stdc++.h>
using namespace std;
int l[5050],m[5050],g[5050];

int main(){
    int t; cin>>t;
    while(t--){
        int n, k; cin>>n>>k;
        for(int i=0 ; i<n ; i++) cin>>l[i]>>m[i]>>g[i];
        
        int lo=0,hi=8030000;
        while(lo+1<hi){
            int mid=(lo+hi)>>1, flag=0;
            for(int i=0 ; i<n ; i++) flag += mid<l[i]-m[i] ? 0 : 1+(min(mid,l[i])-l[i]+m[i])/g[i];
            if(flag<k) lo=mid;
            else hi=mid;
        }
        
        cout<<hi<<'\n';
    }
}
