// https://www.acmicpc.net/problem/
// BOARDCOVER2

// INCOMPLETED
#include"bits/stdc++.h"
using namespace std;

using _2d_vec = std::vector<std::vector<int> >;

int dfs(int x, int y, _2d_vec& table, _2d_vec& visited)
{
    const int way[8][2]={{0,1}, {1,0}, {0,-1}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};

    visited[x][y]=1;
    int ret=1;
    for(int w=0; w<4; w++)
    {
        int nx=x+way[w][0], ny=y+way[w][1];
        if(0<=nx and nx<table.size() and 0<=ny and ny<table[0].size() and !visited[nx][ny])
            ret+=dfs(nx, ny, table, visited);
    }
    return ret;
}

int get_heuristic_ans(_2d_vec& table, _2d_vec& block, int init=0)
{
    static int block_siz;

    if(init)
    {  
        block_siz=0;
        for(auto it : block)
            for(auto it2 : it)
                block_siz+=it2=='#';
    }

    int cnt=0;
    _2d_vec visited(table.size(), vector<int>(table[0].size()));
    for(int i=0; i<table.size(); i++)
        for(int j=0; j<table[0].size(); j++)
            if(!visited[i][j] and table[i][j] == '.')
                cnt+=dfs(i, j, table, visited)/block_siz;
    return cnt;
}

int floating_left_top(_2d_vec& block)
{
    // floating top
    while(true)
    {
        int flag=0;
        for(int i=0; i<block[0].size(); i++)
            if(block[0][i] == '#') flag=1;
        
        if(flag) break;
        for(int i=1; i<block.size(); i++)
            for(int j=0; j<block[0].size(); j++)
                block[i-1][j]=block[i][j], block[i][j]='.';
    }

    // floating left
    while(true)
    {
        int flag=0;
        for(int i=0; i<block.size(); i++)
            if(block[i][0] == '#') flag=1;
        
        if(flag) break;
        for(int i=0; i<block.size(); i++)
            for(int j=1; j<block[0].size(); j++)
                block[i][j-1]=block[i][j], block[i][j]='.';
    }

    return 0;
}

int get_rotated_block(vector<_2d_vec>& rotated_block, _2d_vec& block)
{
    int siz=max(block.size(), block[0].size());
    rotated_block.assign(4, _2d_vec(siz, vector<int>(siz)));

    int n=block.size(), m=block[0].size();
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            rotated_block[0][i][j]=block[i][j];
    
     for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            rotated_block[1][j][n-i-1]=block[i][j];
    
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            rotated_block[2][n-i-1][m-j-1]=block[i][j];

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            rotated_block[3][m-j-1][i]=block[i][j];

    for(int i=0; i<4; i++)
        floating_left_top(rotated_block[i]);

    rotated_block.resize(unique(rotated_block.begin(), rotated_block.end())-rotated_block.begin());
    return 0;
}

int toggle_block(int x, int y, _2d_vec& table, _2d_vec& block, int del=0)
{
    // availity check
    if(!del)
    {
        for(int i=x+block.size()-1; i>=x; i--)
            for(int j=y+block[0].size()-1; j>=y; j--)
                if(block[i-x][j-y]=='#')
                {
                    if(!(0<=i and i<table.size() and 0<=j and j<table[0].size()))
                        return 1;
                    if(table[i][j] != '.')
                        return 1;
                }
    }
    
    // toggle the block
    for(int i=x+block.size()-1; i>=x; i--)
        for(int j=y+block[0].size()-1; j>=y; j--)
            if(block[i-x][j-y]=='#')
            {
                if(table[i][j] == '.') table[i][j]='@';
                else table[i][j]='.';
            }

    return 0;
}

int sol(_2d_vec& table, _2d_vec& block, int ans_cand, int remain_block, int block_siz, int init=0)
{
    static int ans;
    static vector<_2d_vec> rotated_block;

    if(init)
    {
        get_rotated_block(rotated_block, block);
        ans=-1;
    }

    // heuristic using dfs would be very slow.. but
    // if(ans_cand + get_heuristic_ans(table, block, init) <= ans)
    if(ans_cand + remain_block/block_siz <= ans)
        return ans;

    int n=table.size(), m=table[0].size();
    int i,j,flag=0;
    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
        {
            if(table[i][j] == '.') flag=1;
            if(flag) goto _break;
        }
_break:
    if(!flag)
        return ans=max(ans, ans_cand);

    table[i][j]='!'; // uncovered case
    sol(table, block, ans_cand, remain_block, block_siz);
    table[i][j]='.';

    for(int k=0; k<rotated_block.size(); k++) // covered case
    {
        if(toggle_block(i, j, table, rotated_block[k]))
            continue;

        // printf("\n");
        // for(int i=0; i<n; i++)
        // {
        //     for(int j=0; j<m; j++)
        //         printf("%c", table[i][j]);
        //     printf("\n");
        // }

        sol( table, block, ans_cand+1, remain_block, block_siz);
        toggle_block(i, j, table, rotated_block[k], 1);
    }

    return ans;
}

int main(void)
{
#ifdef LOCAL
#endif
    int t; scanf("%d", &t);
    while(t--)
    {
        int n,m,h,c; scanf("%d%d%d%d", &n, &m, &h, &c);
        vector<vector<int> > table(n, vector<int>(m));
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                scanf(" %1c", &table[i][j]);
        
        vector<vector<int> > block(h, vector<int>(c));
            for(int i=0; i<h; i++)
                for(int j=0; j<c; j++)
                    scanf(" %1c", &block[i][j]);
        
        int block_siz=0;
        for(auto it : block)
            for(auto it2 : it)
                block_siz+=it2=='#';

        int table_cnt=0;
        for(auto it : table)
            for(auto it2 : it)
                table_cnt+=it2=='.';

        printf("%d\n", sol(table, block, 0, table_cnt, block_siz, 1));
    }
}

/*

1
5 10 3 3
..........
..........
..........
..........
..........
.#.
###
..#

why 7 why

*/