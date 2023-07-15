#include<bits/stdc++.h>
using namespace std;
map<vector<int>,int> SORTGAME;
queue<pair<vector<int>,int>> bfs;
vector<int> board;
    
void pre_calc(int n){
    board.clear();
    for(int i=1 ; i<=n ; i++) board.push_back(i);
    
    SORTGAME[board]=1;
    bfs.push({board,1});
    
    while(!bfs.empty()){
        vector<int> tmp=bfs.front().first;
        int played=bfs.front().second;
        bfs.pop();
        
        for(int i=0 ; i<n ; i++) for(int j=i+1 ; j<n ; j++){
            vector<int> nxt_board(n);
            for(int k=0 ; k<n ; k++){
                if(i<=k && k<=j) nxt_board[k]=tmp[j-k+i];
                else nxt_board[k]=tmp[k];
            }
            
            
            if(SORTGAME[nxt_board]) continue;
            SORTGAME[nxt_board]=played+1;
            bfs.push({nxt_board,played+1});
        }
    }
}

int main(){
    int c; cin>>c;
    for(int i=1 ; i<=8 ; i++) pre_calc(i);
    
    while(c--){
        int n; cin>>n;
        board.clear();
        
        vector<pair<int,int>> input;
        for(int i=0 ; i<n ; i++){
            int a; cin>>a;
            input.push_back({a,i});
            board.push_back(0);
        }
        sort(input.begin(),input.end());
        for(int i=0 ; i<n ; i++) board[input[i].second]=i+1;
        
        cout<<SORTGAME[board]-1<<'\n';
    }
}
