// https://www.acmicpc.net/problem/
// 2023-03-16 20:32:46
#include"bits/stdc++.h"
using namespace std;

int count_ans(int idx, vector<int>& visited, vector<vector<int> >& graph)
{   
    if(idx==visited.size()) return 1;
    if(visited[idx]) return count_ans(idx+1, visited, graph);

    visited[idx]=1;
    int ret=0;
    for(int next : graph[idx])
        if(!visited[next])
        {
            visited[next]=1;
            ret+=count_ans(idx+1, visited, graph);
            visited[next]=0;
        }
    visited[idx]=0;
    
    return ret;
}

int main(void)
{
#ifdef LOCAL
#endif
    int t; scanf("%d", &t);
    while(t--)
    {
        int n, m; scanf("%d%d", &n, &m);
        vector<vector<int> > graph(n);
        vector<int> used(n);
        for(int i=0; i<m; i++)
        {
            int a,b; scanf("%d%d", &a, &b);
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        printf("%d\n", count_ans(0, used, graph));
    }
}

/*
    
*/
