// https://www.acmicpc.net/problem/
// NUMB3RS
#include"bits/stdc++.h"
using namespace std;

double solution(int now, int d, int p, vector<vector<int> >& graph, int init=0)
{
    static vector<vector<double> > memo;
    if(init) memo=vector<vector<double> > (graph.size(), vector<double>(d+1, -1));

    if(d==0 and now==p) return 1;
    else if(d==0) return 0;
    if(memo[now][d] != -1) return memo[now][d];

    double ret=0;
    for(int i=0; i<graph.size(); i++)
    {
        if(graph[now][i])
            ret+=solution(i, d-1, p, graph)/accumulate(graph[i].begin(), graph[i].end(), 0);
    }
    return memo[now][d]=ret;
}

int main(void)
{
#ifdef LOCAL
#endif
    int t; scanf("%d", &t);
    while(t--)
    {
        int n,d,p; scanf("%d%d%d", &n, &d, &p);
        vector<vector<int> > graph(n, vector<int>(n));
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                scanf("%d", &graph[i][j]);
        int c; scanf("%d", &c);
        while(c--)
        {
            int a; scanf("%d", &a);
            printf("%.8lf ", solution(a, d, p, graph, 1));
        }
        printf("\n");
    }
}

/*
    
*/