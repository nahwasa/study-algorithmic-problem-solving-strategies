#include<bits/stdc++.h>
using namespace std;
int t;vector<int> group;

bool cmp(int x, int y){
    return group[x]^group[y]?group[x]<group[y]:group[x+t]<group[y+t];
}

vector<int> getSA(string &s){
    int n=s.size();
    vector<int> SA(n);
    group.resize(n+1);
    
    for(int i=0 ; i<n ; i++) SA[i]=i, group[i]=s[i];
    group[n]=-1;
    
    for(t=1 ; t<n ; t<<=1){
        sort(SA.begin(),SA.end(),cmp);
        
        vector<int> new_group(n+1);
        new_group[SA[0]]=0; new_group[n]=-1;
        
        for(int i=1 ; i<n ; i++)
            new_group[SA[i]]=new_group[SA[i-1]]+!!cmp(SA[i-1],SA[i]);
        group=new_group;
    }
    
    return SA;
}

int main(){
    cin.tie(0);
    int c; cin>>c;
    while(c--){
        int k; string s; cin>>k>>s;
        vector<int> SA = getSA(s);
        
        int ans=0, strsize=s.size();
        
        for(int n=strsize ; n>=k ; n--){
            int i=SA[n-k], j=SA[n-1], tmp=0;
            while(i<strsize && j<strsize && s[i]==s[j]) i++, j++, tmp++;
            ans=max(ans,tmp);
        }
        
        cout<<ans<<'\n';
    }
}
