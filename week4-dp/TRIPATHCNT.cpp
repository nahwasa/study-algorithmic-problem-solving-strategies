// https://www.acmicpc.net/problem/
// TRIPATHCNT
#include"bits/stdc++.h"
using namespace std;

// return {sum, cnt}
pair<int, int> solution(int x, int y, vector<vector<int> >& tri, int init=0)
{
    static vector<vector<pair<int,int> > > memo;
    if(init) memo=vector<vector<pair<int,int> > >(tri.size(), vector<pair<int,int> >(tri.size(), {-1, 0}));

    if(x==tri.size()-1) return {tri[x][y],1};
    if(memo[x][y].first != -1) return memo[x][y];

    pair<int, int> ret={0,0};
    // x+1, y
    {
        auto tmp=solution(x+1, y, tri);
        tmp.first+=tri[x][y];
        if(tmp.first > ret.first) ret=tmp;
        else if(tmp.first == ret.first) ret.second+=tmp.second;
    }
    // x+1, y+1
    {
        auto tmp=solution(x+1, y+1, tri);
        tmp.first+=tri[x][y];
        if(tmp.first > ret.first) ret=tmp;
        else if(tmp.first == ret.first) ret.second+=tmp.second;
    }
    return memo[x][y]=ret;
}

int main(void)
{
#ifdef LOCAL
#endif
    int t; scanf("%d", &t);
    while(t--)
    {
        int n; scanf("%d", &n);
        vector<vector<int> > tri(n, vector<int>(n));
        for(int i=0; i<n; i++)
            for(int j=0; j<=i; j++)
                scanf("%d", &tri[i][j]);
        printf("%d\n", solution(0, 0, tri, 1).second);
    }
}

/*
    
*/