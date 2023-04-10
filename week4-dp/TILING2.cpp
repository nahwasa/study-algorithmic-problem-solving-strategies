// https://www.acmicpc.net/problem/
// TILING2
// 
#include"bits/stdc++.h"
using namespace std;

int solution(int n)
{
    static vector<int> memo(101, -1);
    
    if(n==0) return 1;
    if(n<0) return 0;
    if(memo[n] != -1) return memo[n];

    int ret=(solution(n-1)+solution(n-2))%(int)(1e9+7);
    return memo[n]=ret;
}

int main(void)
{
#ifdef LOCAL
#endif
    int t; scanf("%d", &t);
    while(t--)
    {
        int n; scanf("%d", &n);
        printf("%d\n", solution(n));
    }
}

/*
    
*/