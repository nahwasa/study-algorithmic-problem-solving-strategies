#include<bits/stdc++.h>
using namespace std;
bool pos[50][50];
int used_food[50], ate_friend[50], n, m;
int ans;

void search(int tmp){
    if(tmp>=ans) return;
    
    int i=0;
    while(i<n && ate_friend[i]>0) i++;
    
    if(i==n){ans=tmp; return;}
    
    for(int j=0 ; j<m ; j++){
        if(pos[i][j] && !used_food[j]){
            used_food[j]=true;
            for(int k=0 ; k<n ; k++) ate_friend[k]+=pos[k][j];
            search(tmp+1);
            used_food[j]=false;
            for(int k=0 ; k<n ; k++) ate_friend[k]-=pos[k][j];
        }
    }
}

int main(){
    int t; cin>>t;
    while(t--){
        cin>>n>>m;
        map<string,int> chingu;
        for(int i=0 ; i<n ; i++){
            string s; cin>>s;
            chingu[s]=i;
        }
        
        fill(pos[0],pos[50],false);
        for(int j=0 ; j<m ; j++){
            int food; cin>>food;
            while(food--){
                string s; cin>>s;
                pos[chingu[s]][j]=true;
            }
        }
        
        ans=m;
        fill(used_food,used_food+m,0);
        fill(ate_friend,ate_friend+n,0);
        search(0);
        cout<<ans<<'\n';
    }
}
