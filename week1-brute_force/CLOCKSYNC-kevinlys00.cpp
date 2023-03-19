#include<bits/stdc++.h>
using namespace std;
const int INF=1e9;
int CLOCK[16];
vector<int> sw[10] = {{0,1,2},{3,7,9,11},{4,10,14,15},{0,4,5,6,7},{6,7,8,10,12},{0,2,14,15},{3,14,15},{4,5,7,14,15},{1,2,3,4,5},{3,4,5,9,13}};

int main(){
    cin.tie(0);
    int C;
    
    for(cin >> C ; C-- ; ){
        for(int i=0 ; i<16 ; i++){
            int a; cin>>a; a/=3; a=4-a;
            CLOCK[i]=a;
        }
        int ans=INF;
        
        for(int i=0 ; i<1<<20 ; i++){
            int k=i, j=10, tmp=0;
            int chk[16];
            fill(chk,chk+16,0);
            while(j--){
                for(int x: sw[j]){
                    chk[x]+=k&3; chk[x]&=3;
                }
                tmp+=k&3; k>>=2;
            }
            
            k=0;
            for(j=0 ; j<16 ; j++) k+=(CLOCK[j]==chk[j]);
            if(k==16) ans=min(ans,tmp);
        }
        
        cout<<(ans==INF?-1:ans)<<'\n';
    }
}
