// https://www.acmicpc.net/problem/
// TIMETRIP
#include"bits/stdc++.h"
using namespace std;

int spfa(vector<vector<pair<int, int> > >& graph, vector<int>& dist, int start)
{
    vector<int> cycle(graph.size()), in_q(graph.size());
    queue<int> q;
    q.push(start);
    dist[start]=0;

    while(q.size())
    {
        auto now=q.front(); q.pop();
        in_q[now]=0;
        for(auto next : graph[now])
            if(dist[next.first] > dist[now]+next.second)
            {
                dist[next.first]=dist[now]+next.second;
                if(!in_q[next.first])
                {
                    cycle[next.first]++;
                    if(cycle[next.first]==graph.size())
                        return 1;
                    in_q[next.first]=1;
                    q.push(next.first);
                }
            }
    }
    return 0;
}

int main(void)
{
#ifdef LOCAL
#endif
    int t; scanf("%d", &t);
    while(t--)
    {
        int n,m; scanf("%d%d", &n, &m);
        vector<vector<pair<int, int> > > graph_forward(n+1), graph_backward(n+1);
        for(int i=0; i<m; i++)
        {
            int a,b,c; scanf("%d%d%d", &a, &b, &c);
            graph_forward[a].push_back({b, c});
            graph_backward[a].push_back({b, -c});
        }

        vector<int> dist_forward(n+1, INT32_MAX), dist_backward(n+1, INT32_MAX);
        vector<int> cycle_forward(n+1), cycle_backward(n+1);
        int flag_forward=spfa(graph_forward, dist_forward, 0), flag_backward=spfa(graph_backward, dist_backward, 0);

        if(dist_forward[1]==INT32_MAX)
            printf("UNREACHABLE\n");
        else
        {
            if(flag_forward) printf("INFINITY ");
            else printf("%d ", dist_forward[1]);
            if(flag_backward) printf("INFINITY\n");
            else printf("%d\n", -dist_backward[1]);
        }
    }
}

/*
    
*/