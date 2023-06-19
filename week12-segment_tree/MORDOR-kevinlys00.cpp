#include<bits/stdc++.h>
using namespace std;
const int MAX = 1<<18;
const int HMAX = 1<<17;
int mn, mx;

int seg[MAX][2];

void update(int t){
    int i=t+HMAX;
    while(i>>1){
    	seg[i>>1][0]=max(seg[i][0],seg[i^1][0]);
    	seg[i>>1][1]=min(seg[i][1],seg[i^1][1]);
        i>>=1;
    }
}

void input(int n){
    for(int i=0 ; i<n ; i++){
    	cin>>seg[i+HMAX][0];
    	seg[i+HMAX][1]=seg[i+HMAX][0];
        update(i);
    }
}

void query(int s, int e, int l, int r, int idx){
    if(r<s || e<l) return;
    if(s<=l && r<=e){
    	mx=max(seg[idx][0],mx);
    	mn=min(seg[idx][1],mn);
        return;
    }
    
    int m=(l+r)>>1;
    query(s,e,l,m,idx<<1);
    query(s,e,m+1,r,(idx<<1)|1);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int c; cin>>c;
    while(c--){
        for(int i=0 ; i<MAX ; i++){
            seg[i][0]=0;
            seg[i][1]=1e5;
        }
        int n, q; cin>>n>>q;
        input(n);
        
        while(q--){
            int s, e; cin>>s>>e;
            mn=1e5, mx=0;
            query(s,e,0,HMAX-1,1);
            cout<<mx-mn<<'\n';
        }
    }
}
