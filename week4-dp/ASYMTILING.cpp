// https://www.acmicpc.net/problem/
// ASYMTILING
#include"bits/stdc++.h"
using namespace std;

long solution(int n)
{
    static vector<int> memo(101,-1);
    if(n<0) return 0;
    if(n==0) return 1;
    if(memo[n] != -1) return memo[n];

    int ret=solution(n-2)+solution(n-1);
    return memo[n]=ret%int(1e9+7);
}

int main(void)
{
#ifdef LOCAL
#endif
    int t; scanf("%d", &t);
    while(t--)
    {
        int n; scanf("%d", &n);
        printf("%ld\n", 
            (solution(n)
            -solution(n/2)
            -((n&1) ? 0:solution(n/2-1))+2*int(1e9+7))
            %int(1e9+7));
    }
}

/*
    ㅁㅁ|ㅁ|ㅁㅁ -> sol(5)-sol(2)
    ㅁㅁ|ㅁ|ㅁㅁ

    ㅁㅁ|ㅁㅁ or ㅁ|ㅁㅁ|ㅁ -> sol(4)-sol(2)-sol(1)
    ㅁㅁ|ㅁㅁ    ㅁ|ㅁㅁ|ㅁ
*/