#include<bits/stdc++.h>
using namespace std;
const int MAX=1<<17;
const int HMAX=1<<16;
int fwt[MAX|1];

int query(int n){
    int t=0;
    for (; n ; n -= n & -n) t = t + fwt[n];
    return t;
}

void update(int n, int x){
    for(; n<=MAX ; n += n & -n) fwt[n] = fwt[n]+x;
}

int main(){
    int c; cin>>c;
    while(c--){
        int n, k; cin>>n>>k; n++;
        fill(fwt,fwt+(MAX|1),0);
        for(int i=1 ; i<=n ; i++) update(i,1);
        
        int idx=2-k;
        int josephus[1010];
        while(--n){
            idx+=k-1;
            if(idx%n == 0) idx = n;
            else if(idx>n) idx %= n;
            
            int x=HMAX;
            for(int t=15 ; t+1 ; t--){
                if(query(x)>=idx) x-=1<<t;
                else x+=1<<t;
            }
            
            if(query(x)>idx) x--;
            else if(query(x)<idx) x++;
            
            josephus[n]=x;
            update(x,-1);
        }
        
        sort(josephus+1,josephus+3);
        cout<<josephus[1]<<' '<<josephus[2]<<'\n';
    }
}
