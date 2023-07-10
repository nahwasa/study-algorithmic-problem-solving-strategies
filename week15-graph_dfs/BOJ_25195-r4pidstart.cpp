// https://www.acmicpc.net/problem/25195
// 
#include"bits/stdc++.h"
using namespace std;

int dfs(int now, int prev, const vector<vector<int> >& graph, const vector<int>& fans)
{
    if(graph[now].size()==0)
        return 1;
    
    for(int next : graph[now])
    {
        if(!fans[next] and dfs(next, now, graph, fans))
                return 1;
    }
    return 0;
}

int main(void)
{
    int n,m; scanf("%d%d", &n, &m);
    vector<vector<int> > graph(n+1);
    for(int i=0; i<m; i++)
    {
        int a,b; scanf("%d%d", &a, &b);
        graph[a].push_back(b);;
    }
    int f; scanf("%d", &f);
    vector<int> fans(n+1);
    for(int i=0; i<f; i++)
    {
        int a; scanf("%d", &a);
        fans[a]=1;
    }

    if(!fans[1] and dfs(1, -1, graph, fans))
        printf("yes");
    else 
        printf("Yes");
}

/*
    
*/
