#include<bits/stdc++.h>
using namespace std;
int dp[121];

int main(){
    cin.tie(0);
    int c; cin>>c;
    while(c--){
        fill(dp,dp+101,0);
        int n; cin>>n;
        
        for(int i=1 ; i<=n ; i++){
            int num[121];
            for(int j=1 ; j<=i ; j++) cin >> num[j];
            for(int j=i ; j ; j--) dp[j]=num[j]+max(dp[j],dp[j-1]);
        }
        
        int ans=-1;
        while(n) ans=max(ans,dp[n--]);
        
        cout<<ans<<'\n';
    }
}
