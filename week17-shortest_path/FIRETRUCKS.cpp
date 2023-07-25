// https://www.acmicpc.net/problem/
// FIRETRUCKS
#include"bits/stdc++.h"
using namespace std;

class dijkstra
{
    // graph[from]={to, cost}, O(ElogV)
    public:
        vector<int> dist;
        dijkstra(int start, const vector<vector<pair<int,int> > > &graph)
        {
            priority_queue<pair<int, int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
            dist.assign(graph.size(), numeric_limits<int>::max()/2);
            pq.push({0, start}), dist[start]=0;
            while(!pq.empty())
            {
                int total_cost=pq.top().first;
                int now=pq.top().second;
                pq.pop();
                
                if(dist[now] < total_cost) continue;
                for(auto next : graph[now])
                {
                    int next_cost=total_cost+next.second;
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
        int n, m, a, b; scanf("%d%d%d%d", &n, &m, &a, &b);
        vector<vector<pair<int, int> > > graph(n+1);
        for(int i=0; i<m; i++)
        {
            int a,b,c; scanf("%d%d%d", &a, &b, &c);
            graph[a].push_back({b, c});
            graph[b].push_back({a, c});
        }
        vector<int> fireplace(a);
        for(int i=0; i<a; i++)
            scanf("%d", &fireplace[i]);
        for(int i=0; i<b; i++)
        {
            int t; scanf("%d", &t);
            graph[0].push_back({t, 0}); // 0 to fire station
        }

        dijkstra dijk(0, graph);
        int ans=0;
        for(int i : fireplace)
            ans+=dijk.dist[i];
        printf("%d\n", ans);
    }
}

/*
    
*/