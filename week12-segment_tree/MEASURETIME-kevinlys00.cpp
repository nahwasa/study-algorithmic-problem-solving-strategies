#include<bits/stdc++.h>
using namespace std;

const int MAX=1<<20;
long int fwt[MAX|1];

long int query(int n){
    long int t=0;
    for(; n ; n -= n & -n) t+=fwt[n];
    return t;
}

void update(int n, int x){
    for(; n<=MAX ; n += n & -n) fwt[n]+=x;
}

long int solve(int n){
    long int ans=0;
    for(int i=0 ; i<n ; i++){
        int a; cin>>a; a++;
        ans+=i-query(a);
        update(a,1);
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int c; cin>>c;
    while(c--){
        fill(fwt,fwt+MAX+1,0);
        int n; cin>>n;
        cout<<solve(n)<<'\n';
    }
}
