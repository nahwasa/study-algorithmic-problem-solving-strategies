#include <bits/stdc++.h>
using namespace std;
#define RR cout<<'R'
#define LL cout<<'L'
#define UU cout<<'U'
#define DD cout<<'D'

void basic(int m, int n){
    if(!n){
        for(int i=0 ; i<m ; i++) RR; DD;
        for(int i=0 ; i<m ; i++) LL; DD;
        return;
    }
    
    if(n-2){
        DD; for(int i=0 ; i<m ; i++) LL;
        DD; for(int i=0 ; i<m ; i++) RR;
        return;
    }
    
    for(int i=0 ; i<m ; i++) DD; RR;
    for(int i=0 ; i<m ; i++) UU; RR;
    return;
}

void BTW(int m, int y){
    for(int i=0;i<y/2;i++) cout<<"DRUR";
    if(y%2) cout<<"DR"; else cout<<"RD";
    for(int i=0;i<(m-y)/2;i++) cout<<"RURD";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    int x, y;
    int mini = 1000;
    
    int arr[n][m];
    for(int i=0 ; i<n ; i++) for(int j=0 ; j<m ; j++){
        cin >> arr[i][j];
        if((i+j)%2){
            mini = min(mini, arr[i][j]);
            
            if(mini==arr[i][j]){
                x=i;
                y=j;
            }
        }
    }
    
    n--; m--;
    
    if(n%2){
        if(m%2){
            for(int i=0 ; i<x/2 ; i++) basic(m,0);
            BTW(m, y);
            for(int i=0 ; i<(n-x)/2 ; i++) basic(m, 1);
        }
        
        else{
            for(int i=0 ; i<m/2 ; i++) basic(n,2);
            for(int i=0 ; i<n ; i++) DD;
        }
    }
        
    
    else{
        for(int i=0 ; i<n/2 ; i++) basic(m,0);
        for(int i=0 ; i<m ; i++) RR;
    }
}
