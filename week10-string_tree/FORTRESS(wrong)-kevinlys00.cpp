#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define FS(i) fortress[i]

bool is_inside(int x1, int y1, int r1, int x2, int y2, int r2){
    return (r1-r2)*(r1-r2)<(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

int main(){
    int c; cin>>c;
    while(c--){
        int n; cin>>n;
        vector<pair<int,pair<int,int>>> fortress;
        fortress.push_back({-20202,{0,0}});
        for(int i=0 ; i<n ; i++){
            int x, y, r; cin>>x>>y>>r;
            fortress.push_back({-r,{x,y}});
        }
        
        sort(fortress.begin(),fortress.end());
        
        vector<int>tree[101];
        int depth[101], deepest=0, idx=0; depth[0]=0;
        for(int i=1 ; i<=n ; i++){
            int tmp=0;
            for(int j=0 ; j<i ; j++){
                if(is_inside(FS(i).ss.ff,FS(i).ss.ss,FS(i).ff,FS(j).ss.ff,FS(j).ss.ss,FS(j).ff))
                    tmp=j;
            }
            tree[i].push_back(tmp);
            tree[tmp].push_back(i);
            if(deepest==depth[tmp]) deepest++, idx=i;
            depth[i]=depth[tmp]+1;
        }
        
        int vt[101], ans=0; fill(vt,vt+n,-1); vt[idx]=0;
        queue<int> bfs; bfs.push(idx);
        
        while(!bfs.empty()){
            int chk=bfs.front(); bfs.pop();
            for(int i=tree[chk].size()-1 ; i+1 ; i--){
                if(vt[tree[chk][i]]==-1){
                    vt[tree[chk][i]]=vt[chk]+1;
                    bfs.push(tree[chk][i]);
                }
                ans=max(ans,vt[tree[chk][i]]);
            }
        }
        
        cout<<ans<<'\n';
    }
}
