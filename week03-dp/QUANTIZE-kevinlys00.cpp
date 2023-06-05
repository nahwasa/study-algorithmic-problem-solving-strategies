#include<bits/stdc++.h>
using namespace std;
int dp[12][101], arr[101], sum[101], sqsum[101], quantize[101][101];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int c; cin>>c;
    while(c--){
        int n, s; cin >> n >> s;
        for(int i=1 ; i<=n ; i++) cin>>arr[i];
        sort(arr+1,arr+n+1);
        for(int i=1 ; i<=n ; i++){
            sum[i]=arr[i]+sum[i-1];
            sqsum[i]=arr[i]*arr[i]+sqsum[i-1];
        }
        
        for(int i=0 ; i<n ; i++) for(int j=i+1 ; j<=n ; j++){
            int chk=sum[j]-sum[i]; chk/=j-i;
            quantize[i][j]=chk*chk*(j-i)-chk*(sum[j]-sum[i])*2+sqsum[j]-sqsum[i];
            chk++;
            quantize[i][j]=min(quantize[i][j],chk*chk*(j-i)-chk*(sum[j]-sum[i])*2+sqsum[j]-sqsum[i]);
        }
        
        fill(dp[0],dp[12],1e9);
        for(int j=1 ; j<=n ; j++) dp[1][j]=quantize[0][j];
        
        for(int i=2 ; i<=s ; i++) for(int j=i ; j<=n ; j++) for(int k=i-1 ; k<j ; k++){
            dp[i][j]=min(dp[i][j],dp[i-1][k]+quantize[k][j]);
        }
        
        cout<<(dp[s][n]==1e9?0:dp[s][n])<<'\n';
    }
}
