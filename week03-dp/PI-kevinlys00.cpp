#include<bits/stdc++.h>
using namespace std;
string s; int dp[10101];

int point(int a, int l){
    string S=s.substr(a-l,l);
    int tmp=10; bool pos;
    
    pos=true;
    for(int i=2 ; i<l ; i++) if(S[i]-S[i-1]!=S[1]-S[0]) pos=false;
    if(pos){
        if(S[1]-S[0]==1 || S[0]-S[1]==1) tmp=2;
        else tmp=5;
    }
    
    pos=true;
    for(int i=2 ; i<l ; i++) if(S[i]^S[i-2]) pos=false;
    if(pos){
        if(S[1]^S[0]) tmp=4;
        else tmp=1;
    }
    
    return tmp;
}

int main(){
    cin.tie(0);
    int c; cin>>c;
    while(c--){
        fill(dp,dp+10101,1e9);
        cin>>s;
        dp[0]=0;
        
        for(int i=3, n=s.size() ; i<=n ; i++) for(int j=3 ; j<=min(i,5) ; j++)
            dp[i]=min(dp[i],dp[i-j]+point(i,j));
        
        cout<<dp[s.size()]<<'\n';
    }
}
