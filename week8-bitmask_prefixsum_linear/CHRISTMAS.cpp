// https://www.acmicpc.net/problem/
// CHRISTMAS
#include"bits/stdc++.h"
using namespace std;

int sol1(int n, int k, vector<int>& arr)
{
    const int mod=20091101;

    vector<int> psum_mod(n+1);
    for(int i=0; i<n; i++)
        psum_mod[i+1]=(psum_mod[i]+arr[i])%k;

    map<int, long> ma;
    for(auto it : psum_mod)
        ma[it]++;
    
    int ret=0;
    for(auto it : ma)
        if(it.second>1)
            ret=(ret + (it.second*(it.second-1)/2))%mod;

    return ret;
}

int dp(int now, vector<int>& data, int init=0)
{
    static vector<int> memo;
    if(init) memo=vector<int>(data.size(), -1);

    if(now==-1) return INT32_MIN;
    if(now==data.size()) return 0;
    if(memo[now] != -1) return memo[now];

    int ret=0;
    // match the closest or just move next
    ret=max(ret, dp(data[now], data)+1);
    ret=max(ret, dp(now+1, data));

    return memo[now]=ret;
}

int sol2(int n, int k, vector<int>& arr)
{
    vector<int> psum_mod(n+1);
    for(int i=0; i<n; i++)
        psum_mod[i+1]=(psum_mod[i]+arr[i])%k;;

    vector<int> shortest_next(n+1), prev(k, -1);
    shortest_next[0]=-1;
    for(int i=n; i>=0; i--)
    {
        shortest_next[i]=prev[psum_mod[i]];
        prev[psum_mod[i]]=i;
    }
    
    return dp(0, shortest_next, 1);
}

int main(void)
{
#ifdef LOCAL
#endif
    int t; scanf("%d", &t);
    while(t--)
    {
        int n,k; scanf("%d%d", &n, &k);
        vector<int> arr(n);
        for(int i=0; i<n; i++)
            scanf("%d", &arr[i]);
        printf("%d\n", sol1(n, k, arr));
        printf("%d\n", sol2(n, k, arr));
    }
}

/*
    
*/