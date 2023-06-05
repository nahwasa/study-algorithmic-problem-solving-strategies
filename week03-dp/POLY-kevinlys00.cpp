#include<bits/stdc++.h>
using namespace std;
long int dp[101][101];
const int MOD=1e7;

int main(){
    cin.tie(0);
    for(int i=1 ; i<101 ; i++){
        dp[i][i]=1;
        for(int j=1 ; j<i ; j++){
            for(int k=1 ; k<=i-j ; k++) dp[i][j]+=(k+j-1)*dp[i-j][k];
            dp[i][j]%=MOD;
        }
    }
    
    int c; cin>>c;
    while(c--){
        int n, ans=0; cin>>n;
        for(int i=1 ; i<=n ; i++) ans+=dp[n][i];
        cout<<ans%MOD<<'\n';
    }
}
