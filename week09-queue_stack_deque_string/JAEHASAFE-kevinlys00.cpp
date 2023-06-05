#include<bits/stdc++.h>
using namespace std;
#define T safe[i]

int main(){
    int c; cin>>c;
    while(c--){
        int n; cin>>n;
        string safe[101];
        for(int i=0 ; i<=n ; i++){
            cin>>safe[i];
            if(i&1) safe[i]+=safe[i];
        }
        
        int ans=n, Z=safe[0].size();
        for(int i=0 ; i<=n ; i+=2){
            int kmp[10101]; fill(kmp,kmp+10101,0);
            for(int x=1, y=0 ; x<Z ; x++){
                while(y && T[x]^T[y]) y=kmp[y-1];
                if(T[x]==T[y]) kmp[x]=++y;
            }
            
            if(i){
                for(int x=0,y=0 ; x<Z<<1 ; x++){
                    while(y && safe[i-1][x]^T[y]) y=kmp[y-1]; 
                    
                    if(safe[i-1][x]==T[y++]){
                        if(y==Z){
                            ans+=x-Z;
                            break;
                        }
                    }
                }
            }
            
            if(i<n){
                for(int x=0,y=0 ; x<Z<<1 ; x++){
                    while(y && safe[i+1][x]^T[y]) y=kmp[y-1]; 
                    
                    if(safe[i+1][x]==T[y++]){
                        if(y==Z){
                            ans+=x-Z;
                            break;
                        }
                    }
                }
            }
        }
        
        cout<<ans<<'\n';
    }
}
