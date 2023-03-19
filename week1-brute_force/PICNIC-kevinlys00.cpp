#include<bits/stdc++.h>
using namespace std;

int used, Wkr[10][10];

int solve(int idx, int n){
    if(used==(1<<n)-1) return 1;
    
    int i,ans=0;
    for(i=idx ; i<n ; i++) if(!(used&(1<<i))) break;
    if(i==n) return 0;
    used^=1<<i;
    for(int j=i+1 ; j<n ; j++){
        if(Wkr[i][j] && !(used&(1<<j))){
            used^=1<<j;
            ans+=solve(i,n);
            used^=1<<j;
        }
    }
    used^=1<<i;
    
    return ans;
}

int main(){
    cin.tie(0);
    int C;
    for(cin >> C ; C-- ; ){
        fill(Wkr[0],Wkr[10],0);
        used=0;
        
        int n,m; cin>>n>>m;
        while(m--){
            int a,b; cin>>a>>b;
            if(a<b) Wkr[a][b]=1;
            else Wkr[b][a]=1;
        }
        
        cout<<solve(0,n)<<'\n';
    }
}
