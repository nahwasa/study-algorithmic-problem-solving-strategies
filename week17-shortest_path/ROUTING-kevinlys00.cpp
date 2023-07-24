#include<bits/stdc++.h>
using namespace std;
#define ff chk.first
#define ss chk.second

int main(){
    long double route[10101];
    int c; cin>>c;
    cout<<fixed;
    cout.precision(10);
    
    while(c--){
        int n, m; cin>>n>>m;
        fill(route,route+n,1e300);
        
        vector<pair<int,long double>> len[10101];
        while(m--){
            int x, y; long double w; cin >> x >> y >> w;
            len[x].push_back({y,w});
            len[y].push_back({x,w});
        }
        
        priority_queue<pair<long double,int>> dijkstra;
        dijkstra.push({-1.0,0}); route[0]=1.0;
        
        while(!dijkstra.empty()){
            pair<long double,int> chk=dijkstra.top(); dijkstra.pop();
            ff=-ff;
            if(route[ss]<ff) continue;
            
            for(auto iter : len[ss]){
                if(route[iter.first] > ff*iter.second){
                    route[iter.first] = ff*iter.second;
                    dijkstra.push({-ff*iter.second,iter.first});
                }
            }
        }
        
        cout<<route[n-1]<<'\n';
    }
}
