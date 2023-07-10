// https://www.acmicpc.net/problem/15681
// 2021-05-17 21:16:48 108ms
#include<bits/stdc++.h>
using namespace std;

vector<int> visited, dp;
vector<vector<int> > tree;

int get_count(int target)
{
    int sum=1; // 자기 자신
    visited[target]++;
    for(int next : tree[target])
        if(visited[next]==0)
            sum+=get_count(next);
    dp[target]=sum;
    return sum;
}

int main(void)
{
    int n, r, q; scanf("%d%d%d", &n,&r,&q);
    // vertex, root, query
    visited.assign(n+1, 0), dp.assign(n+1, 0), tree.assign(n+1, vector<int>());

    for(int i=1; i<n; i++) 
    {
        int a,b; scanf("%d%d", &a,&b);
        tree[a].push_back(b);
        tree[b].push_back(a);    
    }

    get_count(r);

    for(int i=0; i<q; i++)
    {
        int tmp; scanf("%d", &tmp);
        printf("%d\n", dp[tmp]);
    }
}
