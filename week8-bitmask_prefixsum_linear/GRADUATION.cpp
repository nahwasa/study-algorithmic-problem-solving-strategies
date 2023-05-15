// https://www.acmicpc.net/problem/
// GRADUATION
#include"bits/stdc++.h"
using namespace std;

int sol(int now, int sem, int k, vector<int>& open, vector<int>& pre, int l, int init=0)
{
    static vector<vector<int> > memo;
    if(k<=0) return 0;
    if(sem>=open.size()) return INT32_MAX/2;

    if(init) memo=vector<vector<int> >((1<<pre.size())+1, vector<int>((1<<open.size())+1, -1));
    if(memo[now][sem] != -1) return memo[now][sem];

    int n=pre.size(); // lecture count
    int can_apply=0;
    for(int i=0; i<n; i++)
    {
        // check whether he already applied this lecture 
        // or this lecture is open in this semester
        if(now&1<<i or !(open[sem]&1<<i)) continue;
        // check whether he could apply this lecture
        if(pre[i] & ~now) continue;
        can_apply|=1<<i;
    }

    int ret=INT32_MAX/2;
    for(int subset=can_apply; subset; subset=(subset-1)&can_apply)
    {
        int cnt=bitset<32>(subset).count();
        if(cnt > l) continue;
        ret=min(ret, sol(now|subset, sem+1, k-cnt, open, pre, l)+1);
    }
    ret=min(ret, sol(now, sem+1, k, open, pre, l));
    return memo[now][sem]=ret;
}

int main(void)
{
#ifdef LOCAL
#endif
    int t; scanf("%d", &t);
    while(t--)
    {
        int n,k,m,l; scanf("%d%d%d%d", &n, &k, &m, &l);
        vector<int> pre(n);
        for(int i=0; i<n; i++)
        {
            int c; scanf("%d", &c);
            while(c--)
            {
                int a; scanf("%d", &a);
                pre[i]|=1<<a;
            }
        }
        vector<int> open(m);
        for(int i=0; i<m; i++)
        {
            int c; scanf("%d", &c);
            while(c--)
            {
                int a; scanf("%d", &a);
                open[i]|=1<<a;
            }
        }
        int ret=sol(0, 0, k, open, pre, l, 1);
        printf(ret!=INT32_MAX/2 ? "%d\n":"IMPOSSIBLE\n", ret);
    }
}

/*
    
*/