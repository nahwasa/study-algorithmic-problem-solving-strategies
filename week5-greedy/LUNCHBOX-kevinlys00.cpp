#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<pair<int,int>> lunchbox(n);
        for(int i=0 ; i<n ; i++) cin>>lunchbox[i].second;
        for(int i=0 ; i<n ; i++) cin>>lunchbox[i].first;
        sort(lunchbox.begin(), lunchbox.end());
        
        int TIME=0, ans=0;
        while(n--){
            TIME+=lunchbox[n].second;
            ans=max(ans,TIME+lunchbox[n].first);
        }
        
        cout<<ans<<'\n';
    }
}
