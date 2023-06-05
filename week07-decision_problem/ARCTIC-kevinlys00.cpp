#include<bits/stdc++.h>
using namespace std;

bool visited[101];

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
        
        double dst[101][101];
        
        for(int i=0 ; i<n ; i++){
            double a=point[i].first, b=point[i].second;
            dst[i][i]=0;
            for(int j=i+1 ; j<n ; j++){
                double c=point[j].first, d=point[j].second;
                dst[i][j]=dst[j][i]=sqrt((a-c)*(a-c)+(b-d)*(b-d));
            }
        }
        
        double s=0,e=2000;
        
        while(e-s > 1e-4){
            double mid=(s+e)/2;
            int unlinked=n;
            
            fill(visited,visited+n,false);
            visited[0]=true;
            queue<int> q; q.push(0);
            
            while(!q.empty()){
                int now=q.front(); q.pop();
                unlinked--;
                for(int i=0 ; i<n ; i++){
                    if(!visited[i] && dst[now][i]<=mid){
                        visited[i]=true;
                        q.push(i);
                    }
                }
            }
            
            if(unlinked) s=mid;
            else e=mid;
        }
        
        cout<<e<<'\n';
    }
}
