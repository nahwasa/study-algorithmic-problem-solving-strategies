#include<bits/stdc++.h>
using namespace std;
using ll=long int;
ll arr[101010];

ll solve(int l, int r){
    if(l>r) return -1;
    
    int m=(l+r)>>1;
    ll chk=arr[m], fnd=0;
    
    for(int i=m, j=m ; i>=l-1 && j<=r+1 ;){
        while(arr[i]>=chk) i--;
        while(arr[j]>=chk) j++;
        
        fnd=max(fnd,chk*(j-i-1));
        
        if(arr[i]>arr[j]) chk=arr[i--];
        else chk=arr[j++];
    }
    arr[m]=-1;
    
    return max({fnd,solve(l,m-1),solve(m+1,r)});
}

int main(){
    int C; cin>>C;
    while(C--){
        int n; cin>>n;
        for(int i=1; i<=n ; i++) cin>>arr[i];
        
        arr[0]=-1; arr[n+1]=-1;
        cout<<solve(1,n)<<'\n';
    }
}
