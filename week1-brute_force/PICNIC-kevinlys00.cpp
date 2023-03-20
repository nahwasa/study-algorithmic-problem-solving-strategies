#include<bits/stdc++.h>
using namespace std;

int used, Wkr[10][10], n, m;

int solve(){
    if(used+1==1<<n) return 1;
    
    int i,ans=0;
    for(i=0 ; i<n ; i++) if(!(used&1<<i)) break;
    if(i==n) return 0;
    used^=1<<i;
    for(int j=i+1 ; j<n ; j++){
        if(Wkr[i][j] && !(used&1<<j)){
            used^=1<<j;
            ans+=solve();
            used^=1<<j;
        }
    }
    used^=1<<i;
    
    return ans;
}

int main(){
    int C;
    for(cin >> C ; C-- ; ){
        fill(Wkr[0],Wkr[10],0);
        used=0;
        
        cin>>n>>m;
        while(m--){
            int a,b; cin>>a>>b;
            Wkr[a][b]=Wkr[b][a]=1;
        }
        
        cout<<solve()<<'\n';
    }
}
