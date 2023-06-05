#include<bits/stdc++.h>
using namespace std;
string board[10], block[10];
int h, w, r, c, block_size, SS, ans;
vector<vector<pair<int,int>>> cover;
vector<pair<int,int>> subcover;

bool unable(int x, int y, int num){
    int space=0;
    for(int i=x ; i<h ; i++){
        for(int j=(i==x?y:0) ; j<w ; j++){
            space += board[i][j]=='.';
        }
    }
   
    return ans<space/block_size + num? false : true;
}


bool SET(int i, int x, int y, bool num){
    for(int j=0 ; j<block_size ; j++){
        int dx=x+cover[i][j].first, dy=y+cover[i][j].second;
        if(dx<0 || dy<0 || dx>=h || dy>=w) return false;
        
        if(num){
            if(board[dx][dy]=='.') board[dx][dy]='X';
            else{
                if(board[dx][dy]=='X') board[dx][dy]='x';
                else board[dx][dy]='!';
                return false;
            }
        }
        else{
            if(board[dx][dy]=='X')board[dx][dy]='.';
            else{
                if(board[dx][dy]=='x') board[dx][dy]='X';
                else board[dx][dy]='#';
                return false;
            }
        }
    }
    return true;
}


void search(int x, int y, int num){
    if(x==h){ans=max(ans,num); return;}
    if(unable(x,y,num)) return;
   
    if(y==w) search(x+1,0,num);
    else{
        for(int i=0 ; i<SS ; i++){
            if(SET(i,x,y,true)){
                search(x,y+1,num+1);
            }
            SET(i,x,y,false);
        }
        
        search(x,y+1,num);
    }
}

int main(){
    cin.tie(0);
    int t; cin>>t;
    while(t--){
        block_size=0;
        cin>>h>>w>>r>>c;
        for(int i=0 ; i<h ; i++) cin>>board[i];
        for(int i=0 ; i<r ; i++){
            cin>>block[i];
            for(int j=0 ; j<c ; j++) block_size += block[i][j]=='#';
        }
       
        int init_x,init_y;
        for(init_x=0 ; init_x<r ; init_x++){
            for(init_y=0 ; init_y<c ; init_y++){
                if(block[init_x][init_y]=='#')  break;
            }
            if(init_y<c && block[init_x][init_y]=='#') break;
        }
       
        for(int x=0 ; x<r ; x++) for(int y=0 ; y<c ; y++){
            if(block[x][y]=='#') subcover.push_back({x-init_x,y-init_y});
        }
        cover.push_back(subcover);
        subcover.clear();
       
       
        for(init_y=0 ; init_y<c ; init_y++){
            for(init_x=r-1 ; init_x>=0 ; init_x--){
                if(block[init_x][init_y]=='#') break;
            }
            if(init_x>=0 && block[init_x][init_y]=='#') break;
        }
       
        for(int y=0 ; y<c ; y++) for(int x=r-1 ; x>=0 ; x--){
            if(block[x][y]=='#') subcover.push_back({y-init_y,init_x-x});
        }
        cover.push_back(subcover);
        subcover.clear();
       
       
        for(init_x=r-1 ; init_x>=0 ; init_x--){
            for(init_y=c-1 ; init_y>=0 ; init_y--){
                if(block[init_x][init_y]=='#') break;
            }
            if(init_y>=0 && block[init_x][init_y]=='#') break;
        }
       
        for(int x=r-1 ; x>=0 ; x--) for(int y=c-1 ; y>=0 ; y--){
            if(block[x][y]=='#') subcover.push_back({init_x-x,init_y-y});
        }
        cover.push_back(subcover);
        subcover.clear();
       
       
        for(init_y=c-1 ; init_y>=0 ; init_y--){
            for(init_x=0 ; init_x<r ; init_x++){
                if(block[init_x][init_y]=='#') break;
            }
            if(init_x<r && block[init_x][init_y]=='#') break;
        }
       
        for(int y=c-1 ; y>=0 ; y--) for(int x=0 ; x<r ; x++){
            if(block[x][y]=='#') subcover.push_back({init_y-y,x-init_x});
        }
        cover.push_back(subcover);
        subcover.clear();
        sort(cover.begin(),cover.end());
        SS=unique(cover.begin(),cover.end())-cover.begin();
        cover.erase(unique(cover.begin(),cover.end()),cover.end());
        
        ans=0;
        search(0,0,0);
       
        cout<<ans<<'\n';
        cover.clear();
    }
}
