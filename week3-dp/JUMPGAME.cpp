// https://www.acmicpc.net/problem/
// 2023-04-02 19:19:19
#include"bits/stdc++.h"
using namespace std;

int dp(int x, int y, vector<vector<int> >& table, int init=0)
{
    static vector<vector<int> > memo;
    if(init)
        memo=vector<vector<int> >(table.size(), vector<int>(table.size(), -1));
    
    if(x==table.size()-1 and y==table.size()-1) 
        return 1;
    if(memo[x][y] != -1)
        return memo[x][y];

    int ret=0;
    int nx=x+table[x][y], ny=y+table[x][y];

    if(nx<table.size())
        ret+=dp(nx, y, table);    
    if(ny<table.size())
        ret+=dp(x, ny, table);
    
    return memo[x][y]=!!ret;
}
int main(void)
{
#ifdef LOCAL
#endif
    int t; scanf("%d", &t);
    while(t--)
    {
        int n; scanf("%d", &n);
        vector<vector<int> > table(n, vector<int>(n));

        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                scanf("%d", &table[i][j]);
        printf("%s\n", dp(0, 0, table, 1) ? "YES":"NO");
    }
}

/*
    
*/