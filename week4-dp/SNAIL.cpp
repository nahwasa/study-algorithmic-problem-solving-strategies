// https://www.acmicpc.net/problem/
// SNAIL
#include"bits/stdc++.h"
using namespace std;

double solution(int n, int m)
{
    static vector<vector<double> > memo(1001, vector<double>(1001, -1));
    if(n<1) return 1;
    if(m==0 and n>0) return 0;
    if(memo[n][m] != -1) return memo[n][m];

    double ret=0.75*solution(n-2, m-1)+0.25*solution(n-1, m-1);
    return memo[n][m]=ret;
}

int main(void)
{
#ifdef LOCAL
#endif
    int t; scanf("%d", &t);
    while(t--)
    {
        int n,m; scanf("%d%d", &n, &m);
        printf("%.8lf\n", solution(n, m));
    }
}

/*
    
*/