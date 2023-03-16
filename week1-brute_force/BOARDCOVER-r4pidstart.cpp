// https://www.acmicpc.net/problem/
// 2023-03-16 20:53:30
#include"bits/stdc++.h"
using namespace std;

int fill_table(int x, int y, vector<vector<int> >& table)
{
    if(table.size() == x) return 1;
    if(table[0].size() == y) return fill_table(x+1, 0, table);
    if(table[x][y] != '.') return fill_table(x, y+1, table);
    
    const int block[4][4][4]=
    {
        {
            {1, 1},
            {1, 0}
        },
        {
            {1, 0},
            {1, 1}
        },
        {
            {1, 1},
            {0, 1}
        },
        {
            {0, 1},
            {1, 1}
        }
    };
    
    int ret=0;
    if(x+1 != table.size() and y+1 != table[0].size())
    {
        for(int b=0; b<3; b++)
        {
            int flag=0;
            for(int i=0; i<2; i++)
                for(int j=0; j<2; j++)
                    if(block[b][i][j] and table[x+i][y+j] != '.') flag=1;
            if(!flag)
            {
                for(int i=0; i<2; i++)
                    for(int j=0; j<2; j++)
                        if(block[b][i][j])
                            table[x+i][y+j]=1;
                ret+=fill_table(x, y+1, table);
                for(int i=0; i<2; i++)
                    for(int j=0; j<2; j++)
                        if(block[b][i][j])
                            table[x+i][y+j]='.';
            }
        }
    }

    // so tired case
    if(x+1 != table.size() and y!=0)
    {
        if(table[x+1][y-1] == '.' and table[x+1][y] == '.')
        {
            table[x+1][y-1]=1, table[x+1][y]=1, table[x][y]=1;
            ret+=fill_table(x, y+1, table);
            table[x+1][y-1]='.', table[x+1][y]='.', table[x][y]='.';
        }
    }

    return ret;
}

int main(void)
{
#ifdef LOCAL
#endif
    int t; scanf("%d", &t);
    while(t--)
    {
        int n,m; scanf("%d%d", &n, &m);
        vector<vector<int> > table(n, vector<int>(m));
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                scanf(" %c", &table[i][j]);
        printf("%d\n", fill_table(0, 0, table));
    }
}

/*
    
*/
