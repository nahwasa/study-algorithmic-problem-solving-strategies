#include<bits/stdc++.h>
using namespace std;
long int fibo[121]={1,1};
const int MOD=1e9+7;

int main(){
    cin.tie(0);
    for(int i=2 ; i<121 ; i++) fibo[i]=fibo[i-1]+fibo[i-2], fibo[i]%=MOD;
    int c; cin>>c;
    while(c--){
        int n; cin>>n;
        cout<<(fibo[n]+MOD+MOD-fibo[n/2]-(!(n&1))*fibo[n/2-1])%MOD<<'\n';
    }
}
