// https://www.acmicpc.net/problem/
// 2023-03-16 20:09:12
#include"bits/stdc++.h"
using namespace std;

int dfs(int x, int y, int idx, string& s, vector<vector<int> >& table)
{
    static string ss="";
    static vector<vector<vector<int> > > memo;

    if(ss != s)
        ss=s, memo.assign(5, vector<vector<int> >(5, vector<int>(s.size(), -1)));

    if(idx == s.length()) 
        return 1;

    if(memo[x][y][idx] != -1) 
        return memo[x][y][idx];
    
    const int way[8][2]={{0,1}, {1,0}, {0,-1}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};
    for(int i=0; i<8; i++)
    {
        int nx=x+way[i][0], ny=y+way[i][1];
        if(0<=nx and nx<5 and 0<=ny and ny<5 and table[nx][ny]==s[idx] and dfs(nx, ny, idx+1, s, table))
            return 1;
    }    
    return memo[x][y][idx]=0;
}

int check(string& s, vector<vector<int> >& table)
{
    for(int i=0; i<5; i++)
        for(int j=0; j<5; j++)
            if(table[i][j]==s.front() and dfs(i, j, 1, s, table))
                return 1;
    return 0;
}

int main(void)
{
#ifdef LOCAL
#endif
    int t; scanf("%d", &t);
    while(t--)
    {
        vector<vector<int> > table(5, vector<int>(5));
        for(int i=0; i<5; i++)
            for(int j=0; j<5; j++)
                scanf(" %c", &table[i][j]);
        
        int n; scanf("%d", &n);
        while(n--)
        {
            string s; cin >> s;
            printf("%s %s\n", s.c_str(), check(s, table) ? "YES":"NO");
            // cout << s << (check(s, table) ? " YES":" NO") << '\n';
        }
    }
}

/*
    
*/
