#include<bits/stdc++.h>
using namespace std;

int dp[101][101];
string W,F;
vector<string> ans;
int N,M;

bool solve(int w, int f){
    if(dp[w][f]+1) return dp[w][f];
    
    while(w<N && f<M && (W[w]=='?' || W[w]==F[f])) w++, f++;
    
    if(w==N) return f==M;
    
    if(W[w]=='*'){
        if(w==N-1) return 1;
        for(int i=f ; i<M ; i++)
            if(solve(w+1,i)) return dp[w][f]=1;
    }
    return dp[w][f] = 0;
}

int main(){
    cin.tie(0);
    int C; cin>>C;
    while(C--){
        ans.clear();
        cin>>W; N=W.size();
        int name; cin >> name;
        
        while(name--){
            fill(dp[0],dp[101],-1);
            cin>>F; M=F.size();
            
            if(solve(0,0)) ans.push_back(F);
        }
        
        sort(ans.begin(),ans.end());
        
        for(string i : ans) cout<<i<<'\n';
    }
}
