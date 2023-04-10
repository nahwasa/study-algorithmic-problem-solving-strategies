// https://www.acmicpc.net/problem/
// POLY
#include"bits/stdc++.h"
using namespace std;

int solution(int n, int len)
{
    static vector<vector<int> > memo(101, vector<int>(101, -1));
    if(n==len) return 1;
    if(memo[n][len] != -1) return memo[n][len];

    long ret=0;
    for(int i=1; i<=n-len; i++)
        ret=(ret+solution(n-len, i)*(len+i-1))%10000000;

    return memo[n][len]=ret;
}

int sol_sum(int n)
{
    int ret=0;
    for(int i=1; i<=n; i++)
        ret=(ret+solution(n, i))%10000000;
    return ret;
}

int main(void)
{
#ifdef LOCAL
#endif
    int t; scanf("%d", &t);
    while(t--)
    {
        int n; scanf("%d", &n);
        printf("%d\n", sol_sum(n));
    }
}

/*
    
*/