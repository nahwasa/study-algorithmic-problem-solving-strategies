#include<bits/stdc++.h>
using namespace std;
const int MAX=1<<20;
int INV[MAX], PER[MAX];
long int ans;

void merge(int s, int m, int e){
    int i=s, j=m, k=s;
    while(i<m && j<e){
        if(PER[i]>PER[j]) ans+=e-j, INV[k++]=PER[i++];
        else INV[k++]=PER[j++];
    }
    
    while(i<m) INV[k++]=PER[i++];
    while(j<e) INV[k++]=PER[j++];
    
    i=s;
    while(i<e) PER[i++]=INV[i];
}

void solve(int s, int e){
    if(s+1<e){
        int m=(s+e)>>1;
        solve(s,m);
        solve(m,e);
        merge(s,m,e);
    }
}

int main(){
    cin.tie(0);
    
    int n; cin>>n;
    for(int i=0 ; i<n ; i++) cin>>PER[i];
    
    solve(0,n);
    cout<<ans;
}
