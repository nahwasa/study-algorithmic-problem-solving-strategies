#include<bits/stdc++.h>
using namespace std;
int dp[101][101], n, m;
long int arr[101], brr[101], INF=1e10;

int solve(int x, int y){
    if(dp[x][y]+1) return dp[x][y];
    
    long int tmp=min(arr[x],brr[y]);
    
    dp[x][y]=0;
    for(int i=x ; i-- ; ) if(arr[i]<tmp) dp[x][y]=max(dp[x][y],solve(i,y)+1);
    for(int j=y ; j-- ; ) if(brr[j]<tmp) dp[x][y]=max(dp[x][y],solve(x,j)+1);
    
    return dp[x][y];
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int c; cin>>c;
    while(c--){
        cin>>n>>m;
        for(int i=0 ; i<n ; i++) cin>>arr[i];
        for(int j=0 ; j<m ; j++) cin>>brr[j];
        arr[n]=brr[m]=INF;
        
        fill(dp[0],dp[101],-1);
        cout<<solve(n,m)<<'\n';
    }
}
