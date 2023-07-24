#include<bits/stdc++.h>
using namespace std;
queue<int>bfs;
#define f(x,y,z,w) bfs.push(x),bfs.push(y),bfs.push(z),bfs.push(w),vt[x][y][z][w]=1;
int board[10][10], dt[8]={1,-1,0,0,0,0,1,-1};
bool vt[10][10][10][10];
int n,m,x,y,z,w,i,j,mv;char a;

int main(){
    cin.tie(0);
    for(cin>>n>>m;i<n;i++)for(j=0;j<m;board[i][j++]=(a!=79)-(a>36)){
        cin>>a;if(a=='R')x=i,y=j;if(a=='B')z=i,w=j;
    }
    
    f(x,y,z,w);
    while(mv++<10){
        int fnd=bfs.size()/4;
        while(fnd--){
            int a=bfs.front();bfs.pop();
            int b=bfs.front();bfs.pop();
            int c=bfs.front();bfs.pop();
            int d=bfs.front();bfs.pop();
            for(int i=0 ; i<4 ; i++){
                bool chk=0;
                int dy=dt[i],dx=dt[i|4];
                int da=a,db=b,dc=c,dd=d;
                
                board[dc][dd]=1;
                while(!board[da+dy][db+dx]) da+=dy,db+=dx;
                board[dc][dd]=0;
                
                if(board[da+dy][db+dx]<0) chk=1,da+=dy,db+=dx;
                else board[da][db]=1;
                
                while(!board[dc+dy][dd+dx]) dc+=dy,dd+=dx;
                if(!chk)board[da][db]=0;
                if(board[dc+dy][dd+dx]<0){vt[da][db][dc+dy][dd+dx]=1;continue;}
                if(chk){cout << 1; return 0;}

                board[dc][dd]=1;
                while(!board[da+dy][db+dx]) da+=dy,db+=dx;
                board[dc][dd]=0;

                if(!vt[da][db][dc][dd]){
                    bfs.push(da),bfs.push(db),bfs.push(dc),bfs.push(dd);
                    vt[da][db][dc][dd]=1;
                }
            }
        }
    }
    cout<<0;
}
