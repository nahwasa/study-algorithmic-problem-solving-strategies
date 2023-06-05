#include<bits/stdc++.h>
using namespace std;
int uf[10101];

int find(int a){
    if(uf[a]<0) return a;
    return uf[a] = find(uf[a]);
}

bool merge(int a, int b){
    a=find(a);
    b=find(b);
    if(a == b) return false;
    uf[b]=a;
    return true;
}

int main(){
    cin.tie(0); cout<<fixed; cout.precision(2);
    int c; cin>>c;
    while(c--){
        int n; cin>>n;
        vector<pair<double,double>> point;
        for(int i=0 ; i<n ; i++){
            double x, y; cin>>x>>y;
            point.push_back({x,y});
        }
        
        vector<tuple<double,int,int>> edge;
        
        for(int i=0 ; i<n ; i++){
            double a=point[i].first, b=point[i].second;
            for(int j=i+1 ; j<n ; j++){
                double c=point[j].first, d=point[j].second;
                edge.push_back(make_tuple(sqrt((a-c)*(a-c)+(b-d)*(b-d)), i, j));
            }
        }
        
        
        sort(edge.begin(), edge.end());
    
        double ans; int chk=1;
        fill(uf, uf+n, -1);
        for(int i=0 ; chk<n ; i++){
            if(merge(get<1>(edge[i]), get<2>(edge[i]))){
                ans=get<0>(edge[i]);
                chk++;
            }
        }
        
        cout<<ans<<'\n';
    }
}
