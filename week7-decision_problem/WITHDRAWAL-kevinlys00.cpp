#include<bits/stdc++.h>
using namespace std;
int r[1010],c[1010];

int main(){
    int t; cin>>t; cout<<fixed; cout.precision(8);
    while(t--){
        int n, k; cin>>n>>k;
        for(int i=0 ; i<n ; i++) cin>>r[i]>>c[i];
        
        double lo=0, hi=1;
        while(hi-lo>1e-10){
            double mid=(lo+hi)/2;
            vector<double> score;
            for(int i=0 ; i<n ; i++) score.push_back(r[i]-mid*c[i]);
            sort(score.begin(),score.end());
            
            double sum=0;
            for(int i=0 ; i<k ; i++) sum-=score[i];
            
            if(sum<0) lo=mid;
            else hi=mid;
        }
        
        cout<<hi<<'\n';
    }
}
