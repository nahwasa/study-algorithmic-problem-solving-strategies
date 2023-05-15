#include<bits/stdc++.h>
using namespace std;
const int MOD=20091101;

int main(){
    int t; cin>>t;
    while(t--){
        int n, k; cin>>n>>k;
        int arr[101010], remain[101010][2], prev[101010], dp[101010];
        fill(arr,arr+101010,0);
        fill(remain[0],remain[101010],0); remain[0][0]=1;
        fill(prev,prev+101010,-1);
        fill(dp,dp+101010,0);
        
        for(int i=1 ; i<=n ; i++){
            cin>>arr[i];
            arr[i]+=arr[i-1];
            arr[i]%=k;
            if(remain[arr[i]][0]) prev[i]=remain[arr[i]][1];
            remain[arr[i]][0]++;
            remain[arr[i]][1]=i;
            
            dp[i]=dp[i-1];
            if(prev[i]+1) dp[i]=max(dp[i],dp[prev[i]]+1);
        }
        
        long int ans=0;
        for(int i=0 ; i<k ; i++){
            ans += ((long int)remain[i][0]*(remain[i][0]-1)/2)%MOD;
            ans %= MOD;
        }
        
        cout << ans << ' ' << dp[n] << '\n';
    }
}
