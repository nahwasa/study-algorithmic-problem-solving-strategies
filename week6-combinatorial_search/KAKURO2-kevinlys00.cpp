#include<bits/stdc++.h>
using namespace std;
#define POS(i,j,G) pos[length[i][j][G]][hint[i][j][G]][used[i][j][G]]
int pos[10][46][1024];
int board[21][21], length[21][21][2], hint[21][21][2], used[21][21][2], n;

void TRY(int x, int y, int num){
    board[x][y]=num;
    int i;
    for(i=y-1 ; i>0 && board[x][i]>=0 ; i--) used[x][i][0]|=1<<num, hint[x][i][0]-=num, length[x][i][0]--;
    for(i=y+1 ; i<=n && board[x][i]>=0 ; i++) used[x][i][0]|=1<<num, hint[x][i][0]-=num, length[x][i][0]--;
    for(i=x-1 ; i>0 && board[i][y]>=0 ; i--) used[i][y][1]|=1<<num, hint[i][y][1]-=num, length[i][y][1]--;
    for(i=x+1 ; i<=n && board[i][y]>=0 ; i++) used[i][y][1]|=1<<num, hint[i][y][1]-=num, length[i][y][1]--;
}

void ERASE(int x, int y, int num){
    board[x][y]=0;
    int i;
    for(i=y-1 ; i>0 && board[x][i]>=0 ; i--) used[x][i][0]^=1<<num, hint[x][i][0]+=num, length[x][i][0]++;
    for(i=y+1 ; i<=n && board[x][i]>=0 ; i++) used[x][i][0]^=1<<num, hint[x][i][0]+=num, length[x][i][0]++;
    for(i=x-1 ; i>0 && board[i][y]>=0 ; i--) used[i][y][1]^=1<<num, hint[i][y][1]+=num, length[i][y][1]++;
    for(i=x+1 ; i<=n && board[i][y]>=0 ; i++) used[i][y][1]^=1<<num, hint[i][y][1]+=num, length[i][y][1]++;
}


bool search(){
    int x=0, y=0, minpos=10, mincand=1023;
    
    for(int i=1 ; i<=n && minpos ; i++) for(int j=1 ; j<=n && minpos ; j++){
        if(!board[i][j]){
            int s = POS(i,j,0) & POS(i,j,1) & (~used[i][j][0]) & (~used[i][j][1]);
            int a=0;
            for(int b=1 ; b<10 ; b++) a+=(s&(1<<b))>0;
            if(minpos>a){mincand=s; minpos=a; x=i; y=j;}
        }
    }
    
    if(!minpos){/*
        cout<<"FAILED IN : "<<x<<' '<<y<<'\n';
        cout<<length[x][y][0]<<' '<<used[x][y][0]<<' '<<hint[x][y][0]<<'\n';
        cout<<length[x][y][1]<<' '<<used[x][y][1]<<' '<<hint[x][y][1]<<'\n';*/
        return false;
    }
    
    if(!y){
        for(int i=1 ; i<=n ; i++){
            for(int j=1 ; j<=n ; j++) cout<<(board[i][j]<0?0:board[i][j])<<' ';
            cout<<'\n';
        }
        return true;
    }
    
    for(int i=1 ; i<10 ; i++){
        if(mincand & (1<<i)){
            TRY(x,y,i); //cout<<"TRY : "<< x<<' '<<y<<" IN "<< i<<'\n';
            if(search()) return true;
            ERASE(x,y,i);
        }
    }
    
    return false;
}


int main(){
    cin.tie(0);
    
    for(int i=2 ; i<1024 ; i+=2){
        int len=0, sum=0;
        int j=i;
        for(int k=1 ; k<10 ; k++)
            if(j&(1<<k)){len++; sum+=k;}
        
        for(j=1022 ; j>=0 ; j-=2) pos[len][sum][j] |= (i & ~j);
    }
    
    
    int t; cin>>t;
    while(t--){
        fill(board[0], board[21], -1);
        fill(length[0][0], length[21][0], 0);
        fill(hint[0][0], hint[21][0], 0);
        fill(used[0][0], used[21][0], 0);
        
        cin>>n;
        for(int i=1 ; i<=n ; i++) for(int j=1 ; j<=n ; j++){
            int k; cin>>k;
            board[i][j]+=k;
        }
        
        int q; cin>>q;
        while(q--){
            int x, y, dir, sum; cin>>x>>y>>dir>>sum;
            if(dir){
                int i=x;
                while(++i<=n && !board[i][y]) hint[i][y][dir]=sum;
                int tmp=i-x-1;
                while(--i>x) length[i][y][dir]=tmp;
            }
            else{
                int j=y;
                while(++j<=n && !board[x][j]) hint[x][j][dir]=sum;
                int tmp=j-y-1;
                while(--j>y) length[x][j][dir]=tmp;
            }
        }
        
        search();
        
    }
}
