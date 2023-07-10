// https://www.acmicpc.net/problem/1987
// 2021-09-25 03:39:52 748ms
#include<bits/stdc++.h>
using namespace std;

int ans=0,r,c;
vector<vector<char> > table;
vector<char> visited(26);

const int w[4][2]={{0,1}, {0,-1}, {1,0}, {-1,0}};
void dfs(int x, int y, int cnt)
{
    if(visited[table[x][y]-'A']) return;
    visited[table[x][y]-'A']=1;
    ans=max(ans, cnt);

    for(int i=0; i<4; i++)
    {
        int nx=x+w[i][0], ny=y+w[i][1];
        if(0<=nx && nx<r && 0<=ny && ny<c)
            dfs(nx, ny, cnt+1);
    }

    visited[table[x][y]-'A']=0;
}

int main(void)
{
    scanf("%d%d", &r, &c);
    table.assign(r, vector<char>(c, 0));
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            scanf(" \n%c", &table[i][j]);
    dfs(0,0,1);
    printf("%d", ans);
}

/*
    
*/
