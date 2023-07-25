// https://www.acmicpc.net/problem/
// PROMISES
#include"bits/stdc++.h"
using namespace std;

class Floyd
{
    // adjacent matrix 1~n, O(V^3)
    public:
        vector<vector<int> > dist;
        Floyd(const vector<vector<int> >& graph)
        {
            dist=graph;
            for(int k=1; k<dist.size(); k++)
                for(int i=1; i<dist.size(); i++)
                    for(int j=1; j<dist.size(); j++)
                        dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
        }
        void update(int a, int b)
        {
            for(int i=1; i<dist.size(); i++)
                for(int j=1; j<dist.size(); j++)
                    dist[i][j]=min({dist[i][j], dist[i][a]+dist[b][j]+dist[a][b], dist[i][b]+dist[a][j]+dist[a][b]});
        }
};

int main(void)
{
#ifdef LOCAL
#endif
    int t; scanf("%d", &t);

    while(t--)
    {
        int n,m,k; scanf("%d%d%d", &n, &m, &k);
        vector<vector<int> > graph(n+1, vector<int>(n+1, INT32_MAX/3));
        
        for(int i=0; i<=n; i++)
            graph[i][i]=0;

        for(int i=0; i<m; i++)
        {
            int a,b,c; scanf("%d%d%d", &a, &b, &c);
            a++, b++;
            graph[a][b]=min(graph[a][b], c);
            graph[b][a]=min(graph[a][b], c);
        }

        Floyd prev=Floyd(graph);
        int ans=0;
        while(k--)
        {
            Floyd tmp=prev;
            int a,b,c; scanf("%d%d%d", &a, &b, &c);
            a++, b++;
            tmp.dist[a][b]=min(tmp.dist[a][b], c);
            tmp.dist[b][a]=min(tmp.dist[b][a], c);
            tmp.update(a, b);

            if(tmp.dist == prev.dist)
                ans++;
            else
                prev=std::move(tmp);
        }
        printf("%d\n", ans);
    }
}

/*
    
*/