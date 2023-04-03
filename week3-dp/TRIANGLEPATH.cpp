// https://www.acmicpc.net/problem/
// 2023-04-02 19:53:18
#include"bits/stdc++.h"
using namespace std;

int dp(int x, int y, vector<vector<int> >& table, int init=0)
{
    static vector<vector<int> > memo;
    if(init)
        memo=vector<vector<int> >(table.size(), vector<int>(table.size(), -1));
    
    if(x==table.size())
        return 0;
    if(memo[x][y] != -1)
        return memo[x][y];

    int ret=max(dp(x+1, y, table), dp(x+1, y+1, table))+table[x][y];
    return memo[x][y]=ret;
}
int find_max_path(vector<vector<int> >& table)
{
    int tmp=0;
    for(int i=0; i<table.size(); i++)
        tmp=max(tmp, dp(0, 0, table, tmp==0));
    return tmp;
}

int main(void)
{
#ifdef LOCAL
#endif
    int t; scanf("%d", &t);
    while(t--)
    {
        int n; scanf("%d", &n);
        vector<vector<int> > table(n, vector<int>(n, INT32_MIN/2));
        for(int i=0; i<n; i++)
            for(int j=0; j<=i; j++)
                scanf("%d", &table[i][j]);
        
        printf("%d\n", find_max_path(table));
    }
}

/*
    
*/