// https://www.acmicpc.net/problem/
// ROUTING
#include"bits/stdc++.h"
using namespace std;

class dijkstra
{
    // graph[from]={to, cost}, O(ElogV)
    public:
        vector<double> dist;
        dijkstra(int start, const vector<vector<pair<int,double> > > &graph)
        {
            priority_queue<pair<double, int>, vector<pair<double,int> >, greater<pair<double,int> > > pq;
            dist.assign(graph.size(), numeric_limits<double>::max());
            pq.push({1, start}), dist[start]=1;
            while(!pq.empty())
            {
                double total_cost=pq.top().first;
                int now=pq.top().second;
                pq.pop();
                
                if(dist[now] < total_cost) continue;
                for(auto next : graph[now])
                {
                    double next_cost=total_cost*next.second;
                    if(dist[next.first]>next_cost) 
                    {
                        dist[next.first]=next_cost;
                        pq.push({next_cost, next.first});
                    }
                }
            }
        }
};

int main(void)
{
#ifdef LOCAL
#endif
    int t; scanf("%d", &t);
    while(t--)
    {
        int n,m; scanf("%d%d", &n, &m);
        vector<vector<pair<int, double> > > graph(n+1);
        for(int i=0; i<m; i++)
        {
            int a, b; double c;
            scanf("%d%d%lf", &a, &b, &c);
            graph[a].push_back({b, c});
            graph[b].push_back({a, c});
        }
        dijkstra dijk(0, graph);
        printf("%.10lf\n", dijk.dist[n-1]);
    }
}

/*
    
*/