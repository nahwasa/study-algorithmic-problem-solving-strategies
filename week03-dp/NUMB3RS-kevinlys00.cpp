#include<bits/stdc++.h>
using namespace std;
long double lnk[54][54], dp[54], nxt[54];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cout.precision(8); cout<<fixed;
    int c; cin>>c;
    while(c--){
        int n, d, p; cin>>n>>d>>p;
        for(int i=0 ; i<n ; i++){
            long double sum=0.0;
            for(int j=0 ; j<n ; j++){
                cin>>lnk[i][j];
                sum+=lnk[i][j];
            }
            for(int j=0 ; j<n ; j++) if(lnk[i][j]>0.0) lnk[i][j]/=sum;
        }
        
        fill(dp,dp+n,0); dp[p]=1;
        
        while(d--){
            fill(nxt,nxt+n,0);
            for(int j=0 ; j<n ; j++) for(int k=0 ; k<n ; k++) nxt[k]+=dp[j]*lnk[j][k];
            for(int j=0 ; j<n ; j++) dp[j]=nxt[j];
        }
        
        int t; cin>>t;
        for(int i=0 ; i<t ; i++){
            cin>>p;
            cout<<dp[p];
            cout<<(i==t-1?'\n':' ');
        }
    }
}
