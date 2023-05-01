// https://www.acmicpc.net/problem/
// KAKURO2

// INCOMPLETE
#include"bits/stdc++.h"
#include<cassert>
using namespace std;

struct st
{
    int len, remain_len_h, remain_len_v, dir; // 0 -> right, 1 -> bottom
    pair<int,int> ret;
};
st find_shortest(vector<vector<int> >& table, vector<vector<pair<int, int> > >& hint)
{
    int len=INT32_MAX, remain_len_h, remain_len_v, dir=-1;
    pair<int,int> ret={-1, -1};
    int n=table.size();
    {
        // to right
        vector<vector<int> > visited(n, vector<int>(n));
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
            {
                if(table[i][j] == 0 and !visited[i][j])
                {
                    int cnt=0, tmp=j;
                    while(tmp<n and table[i][tmp] == 0)
                    {
                        cnt++;
                        visited[i][tmp]=1;
                        tmp++;
                    }
                    if(cnt < len)
                    {
                        len=cnt;
                        remain_len_h=tmp-j;
                        {
                            int cnt=0, tmp=i;
                            while(tmp<n and table[tmp][j] == 0)
                            {
                                cnt++;
                                // visited[tmp][j]=1;
                                tmp++;
                            }
                            remain_len_v=tmp-i;
                        }
                        ret={i, j};
                        dir=0;
                    }
                }
            }
    }

    {
        // to bottom
        vector<vector<int> > visited(n, vector<int>(n));
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
            {
                if(table[i][j] == 0 and !visited[i][j])
                {
                    int cnt=0, tmp=i;
                    while(tmp<n and table[tmp][j] == 0)
                    {
                        cnt++;
                        visited[tmp][j]=1;
                        tmp++;
                    }
                    if(cnt < len)
                    {
                        len=cnt;
                        remain_len_v=tmp-i;
                        {
                            int cnt=0, tmp=j;
                            while(tmp<n and table[i][tmp] == 0)
                            {
                                cnt++;
                                // visited[i][tmp]=1;
                                tmp++;
                            }
                            remain_len_h=tmp-j;
                        }
                        ret={i, j};
                        dir=1;
                    }
                }
            }
    }

    return {len, remain_len_h, remain_len_v, dir, ret};
}

struct ch
{
    int max_num;
    bitset<10> used;
    int remain_x, remain_y;
};
ch check_line(st& sh, vector<vector<int> >& table, vector<vector<pair<int, int> > >& hint)
{
    ch ret={INT32_MAX, 0};
    // to left
    {
        // check the hint and bitmask using numbers
        bitset<10> used;
        int x=sh.ret.first, y=sh.ret.second-1;
        int sum=0;
        // assert(table[x][y] != -1);
        while(table[x][y] != -1)
            used[table[x][y]]=1, ret.used[table[x][y]]=1, sum+=table[x][y], y--;

        int available_max=0;
        for(int i=9, l=sh.remain_len_h; i>=1 and l; i--)
            if(!used[i]) available_max+=i, l--;

        ret.max_num=min(hint[x][y].second - sum, ret.max_num);
        if(hint[x][y].second - sum > available_max)
            ret.max_num=-1;
        ret.remain_x=hint[x][y].second - sum;
    }
    // to top
    {
        // check the hint and bitmask using numbers
        bitset<10> used;
        int x=sh.ret.first-1, y=sh.ret.second;
        int sum=0;
        // assert(table[x][y] != -1);
        while(table[x][y] != -1)
            used[table[x][y]]=1, ret.used[table[x][y]]=1, sum+=table[x][y], x--;
        
        int available_max=0;
        for(int i=9, l=sh.remain_len_v; i>=1 and l; i--)
            if(!used[i]) available_max+=i, l--;

        ret.max_num=min(hint[x][y].first - sum, ret.max_num);
        if(hint[x][y].first - sum > available_max)
            ret.max_num=-1;
        ret.remain_y=hint[x][y].first - sum;
    }

    return ret;
}

int find_solution(vector<vector<int> >& table, vector<vector<pair<int, int> > >& hint)
{
    // find the shortest line
    auto shortest=find_shortest(table, hint);
    if(shortest.len == -1) // all clear!
        return 1;


    printf("\n");
    for(int i=0; i<table.size(); i++)
    {
        for(int j=0; j<table.size(); j++)
            printf("%d ", table[i][j]);
        printf("\n");
    }

    // pruning
    ch checked=check_line(shortest, table, hint);
    if(shortest.remain_len_h == 1 and shortest.remain_len_v == 1)
    {
        if(checked.remain_x!=checked.remain_y)
            return 0;
    }
    if(checked.max_num < 0) return 0;

    int x=shortest.ret.first, y=shortest.ret.second;
    if(shortest.remain_len_h == 1) 
    {
        if(checked.used[checked.remain_x]) return 0;
        table[x][y]=checked.remain_x;
        if(find_solution(table, hint))
            return 1;
        table[x][y]=0;
        return 0;
    }
    else if(shortest.remain_len_v == 1)
    {
        if(checked.used[checked.remain_y]) return 0;
        table[x][y]=checked.remain_y;
        if(find_solution(table, hint))
            return 1;
        table[x][y]=0;
        return 0;
    }
    for(int i=1, ma=min(checked.max_num, 9); i<=ma; i++)
    {
        if(checked.used[i]) continue;
        table[x][y]=i;
        if(find_solution(table, hint))
            return 1;
    }

    table[x][y]=0;
    return 0;
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
            {
                scanf("%d", &table[i][j]);
                if(table[i][j] != 1) table[i][j]=-1;
                else table[i][j]=0;
            }
        
        // {col_hint, row_hint}
        vector<vector<pair<int, int> > > hint(n, vector<pair<int,int> >(n));
        int m; scanf("%d", &m);
        for(int i=0; i<m; i++)
        {
            int a,b,c,d; scanf("%d%d%d%d", &a, &b, &c, &d);
            if(c==0) hint[a-1][b-1].second=d;
            else hint[a-1][b-1].first=d;
        }

        assert(find_solution(table, hint));
        printf("\n");
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
                printf("%d ", table[i][j] == -1 ? 0 : table[i][j]);
            printf("\n");
        }
    }
}

/*
    
*/