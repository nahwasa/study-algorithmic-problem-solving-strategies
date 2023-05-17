#include<bits/stdc++.h>
using namespace std;
using ui=unsigned int;

int main(){
    int c; cin>>c;
    while(c--){
        ui k, n; cin >> k >> n;
        queue<ui> Q; Q.push(1984u);
        ui sum=1984u, prev=1983u; int ans=sum==k;
        while(--n){
            prev=prev*214013u+2531011u;
            ui chk=prev; chk%=10000; chk++; sum += chk;
            Q.push(chk);
            
            while(sum>k && Q.size()>1){
                sum -= Q.front();
                Q.pop();
            }
            if(sum==k) ans++;
        }
        
        cout<<ans<<'\n';
    }
}
