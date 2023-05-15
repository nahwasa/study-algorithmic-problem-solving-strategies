#include<bits/stdc++.h>
using namespace std;
const int INF=1e9;

int main(){
    int c; cin>>c;
    while(c--){
        int n, k, m, l; cin >> n >> k >> m >> l;
        int pre[12]; fill(pre,pre+12,0);
        for(int i=0 ; i<n ; i++){
            int tmp; cin>>tmp;
            for(int j=0 ; j<tmp ; j++){
                int a; cin>>a;
                pre[i]|=1<<a;
            }
        }
        
        int subject[10]; fill(subject,subject+12,0);
        for(int i=0 ; i<m ; i++){
            int tmp; cin>>tmp;
            for(int j=0 ; j<tmp ; j++){
                int a; cin>>a;
                subject[i]|=1<<a;
            }
        }
        
        int dp[12][1<<12]; fill(dp[0],dp[11],INF);
        dp[0][0]=0;
        int i, j; bool imp=true;
        
        for(i=0 ; i<=m && imp ; i++){
            for(j=0 ; j<1<<n ; j++){
                if(dp[i][j]==INF) continue;
                if(__builtin_popcount(j)>=k){imp=false; break;}
                int tmp = subject[i] & (~j);
                
                for(int Z=0 ; Z<n ; Z++){
                    if((pre[Z] & j) != pre[Z]) tmp &= ~(1<<Z);
                }
                
                for(int Z=tmp ; Z>0 ; Z=(Z-1)&tmp){
                    if(__builtin_popcount(Z)<=l){
                        dp[i+1][j|Z]=min(dp[i+1][j|Z],dp[i][j]+1);
                    }
                }
                
                dp[i+1][j]=min(dp[i+1][j],dp[i][j]);
            }
        }   
        
        if(imp) cout<<"IMPOSSIBLE\n";
        else cout<<dp[i-1][j]<<'\n';
    }
}
