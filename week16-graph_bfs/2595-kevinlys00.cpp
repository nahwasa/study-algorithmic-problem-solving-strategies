#include<bits/stdc++.h>
using namespace std;

string solve(int x, int y, int n){
    bool vt[n];
    fill(vt,vt+n,0); vt[x]=vt[y]=1;
    queue<pair<int,string>> q;
    if(x) q.push({x,to_string(x)});
    if(y) q.push({y,to_string(y)});
    
    while(!q.empty()){
        for(int i=q.size() ; i-- ; ){
            int z=q.front().first*10;
            string str=q.front().second;
            q.pop();
            
            if((z+x)%n==0) return str+to_string(x);
            if((z+y)%n==0) return str+to_string(y);
            
            if(!vt[(z+x)%n]){
                vt[(z+x)%n]=1;
                q.push({(z+x)%n,str+to_string(x)});
            }
            if(!vt[(z+y)%n]){
                vt[(z+y)%n]=1;
                q.push({(z+y)%n,str+to_string(y)});
            }
        }
    }
    
    return "Z";
}

int main(){
    cin.tie(0); ios::sync_with_stdio(0);
    int n; cin>>n;
    int cnt[10]={0,1,2,3,4,5,6,7,8,9};
    
    if(n<10){cout<<n; return 0;}
    
    for(int i=1 ; i<n ; i++){
        for(int j=1 ; j<10 ; j++){
            if(cnt[j]==0){
                for(int k=0 ; k<i ; k++) cout<<j;
                return 0;
            }
            else cnt[j]=(cnt[j]*10+j)%n;
        }
    }
    
    string ans="0";
    for(int i=0 ; i<20 ; i++) ans+=ans;
    
    for(int i=0 ; i<9 ; i++){
        for(int j=i+1 ; j<10 ; j++){
            string tmp=solve(i,j,n);
            if(tmp!="Z"){
                if(tmp.size()<ans.size()) ans=tmp;
                else if(tmp.size()==ans.size() && tmp.compare(ans)<0) ans=tmp;
            }
        }
    }
    
    cout<<ans;
}
