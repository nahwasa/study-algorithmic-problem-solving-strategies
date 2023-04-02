#include<bits/stdc++.h>
using namespace std;
int dp[505], num[505], chk[505];

int main(){
    cin.tie(0);
    int c; cin>>c;
    while(c--){
        fill(dp,dp+505,0);
        fill(chk,chk+505,0);
        
        int n; cin>>n;
        int ans=1;
        cin>>num[0]; chk[0]=1; dp[1]=num[0];
        
        for(int i=1 ; i<n ; i++){
            cin>>num[i];
            if(dp[ans]<num[i]) dp[++ans]=num[i], chk[i]=ans;
            else dp[lower_bound(dp+1,dp+ans,num[i])-dp]=num[i], chk[i]=lower_bound(dp+1,dp+ans,num[i])-dp;
        }
        cout<<ans<<'\n';
    }
}
