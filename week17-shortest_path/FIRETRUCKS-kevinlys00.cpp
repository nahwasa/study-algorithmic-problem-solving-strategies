#include<bits/stdc++.h>
using namespace std;
#define ff chk.first
#define ss chk.second

int main(){
    int t[10101];
    int c; cin>>c;
    
    while(c--){
        int v, e, n, m; cin>>v>>e>>n>>m;
        fill(t,t+v+1,1e9);
        
        vector<pair<int,int>> len[1010];
        while(e--){
            int x, y, w; cin >> x >> y >> w;
            len[x].push_back({y,w});
            len[y].push_back({x,w});
        }
        
        vector<int>fire ,station;
        while(n--){int a; cin>>a; fire.push_back(a);}
        while(m--){
            int a; cin>>a;
            station.push_back(a);
            len[0].push_back({a,0});
        }
        
        
        priority_queue<pair<int,int>> dijkstra;
        dijkstra.push({0,0}); t[0]=0;
        
        while(!dijkstra.empty()){
            pair<int,int> chk=dijkstra.top(); dijkstra.pop();
            if(t[ss]+ff>0) continue;
            
            for(auto iter : len[ss]){
                if(t[iter.first]+ff-iter.second>0){
                    t[iter.first] = iter.second-ff;
                    dijkstra.push({ff-iter.second,iter.first});
                }
            }
        }
        
        int ans=0;
        for(int i:fire) ans+=t[i];
        cout<<ans<<'\n';
    }
}
