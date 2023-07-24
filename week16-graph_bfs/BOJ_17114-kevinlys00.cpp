#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[12]; arr[0]=1;
    for(int i=1 ; i<=11 ; i++){
        cin>>arr[i];
        arr[i]*=arr[i-1];
    }
    int cnt=0;
    queue<int> bfs;
    int bm[1<<20];
    for(int i=0 ; i<arr[11] ; i++){
        cin>>bm[i];
        cnt+=!!bm[i];
        if(bm[i]>0) bfs.push(i);
    }
    
    int ans=0;
    while(!bfs.empty()){
        int bs=bfs.size();
        while(bs--){
            int tmp=bfs.front(); bfs.pop();
            for(int i=0 ; i<11 ; i++){
                if((tmp+arr[i])/arr[i+1] == tmp/arr[i+1] && !bm[tmp+arr[i]]){
                    cnt++;
                    bm[tmp+arr[i]]=1;
                    bfs.push(tmp+arr[i]);
                }
                
                if((tmp-arr[i])/arr[i+1] == tmp/arr[i+1] && tmp>=arr[i] && !bm[tmp-arr[i]]){
                    cnt++;
                    bm[tmp-arr[i]]=1;
                    bfs.push(tmp-arr[i]);
                }
            }
        }
        ans++;
    }
    
    cout<<(cnt==arr[11]?ans-1:-1);
}
