#include<bits/stdc++.h>
using namespace std;

int main(){
    int c; cin>>c;
    while(c--){
        string T; cin>>T;
        string inv=T;
        reverse(inv.begin(),inv.end());
        int Z=T.size(), x, y;
        int kmp[101010]; fill(kmp,kmp+101010,0);
        
        for(x=1, y=0 ; x<Z ; x++){
            while(y && inv[x]^inv[y]) y=kmp[y-1];
            if(inv[x]==inv[y]) kmp[x]=++y;
        }
        
        for(x=0, y=0 ; x<Z ; x++){
            while(y && T[x]^inv[y]) y=kmp[y-1]; 
            y++;
        }
        
        cout<<(Z<<1)-y<<'\n';
    }
}
