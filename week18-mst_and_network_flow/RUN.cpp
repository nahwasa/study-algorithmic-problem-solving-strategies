// https://www.acmicpc.net/problem/
// LAN
#include"bits/stdc++.h"
using namespace std;

class kruskal
{
    // edge={cost, {from, to}}, O(ElogE+E)
    public:
        class Dsu
        {
            private:
                vector<int> parent;
            public:
                Dsu(int size)
                {
                    parent.assign(size, -1);
                }
                int find(int i)
                {
                    if(parent[i]<0) return i;
                    else return parent[i]=find(parent[i]);
                }
                int merge(int a, int b)
                {
                    a=find(a), b=find(b);
                    if(a==b) return 1;

                    if(parent[a]>parent[b]) swap(a,b);
                    parent[a]+=parent[b];
                    parent[b]=a;
                    return 0;
                }
        };
    public:
        double cost=0;
        vector<int> used_edge;
        kruskal(int size, vector<pair<double, pair<int,int> > >& edge, int m)
        {
            Dsu dsu(size);
            for(int i=0; i<m; i++)
            {
                int a,b; scanf("%d%d", &a, &b);
                dsu.merge(a,b);
            }
            used_edge.assign(edge.size(),0);
            sort(edge.begin(), edge.end());
            int cnt=0;
            for(int i=0; i<edge.size(); i++)
                if(!dsu.merge(edge[i].second.first, edge[i].second.second))
                    cost+=edge[i].first, used_edge[i]=1, cnt++;

            // if(cnt != size-1) cost=-1;
        }
};

inline double get_dist(const pair<int, int>& a, const pair<int, int>& b)
{
    return sqrt((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));
}

int main(void)
{
#ifdef LOCAL
#endif
    int t; scanf("%d", &t);
    while(t--)
    {
        int n,m; scanf("%d%d", &n, &m);
        vector<pair<int,int> > point(n);
        for(int i=0; i<n; i++)
            scanf("%d", &point[i].first);
        for(int i=0; i<n; i++)
            scanf("%d", &point[i].second);

        vector<pair<double, pair<int,int> > > graph;
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                graph.push_back({get_dist(point[i], point[j]), {i, j}});
        printf("%.8lf\n", kruskal(n, graph, m).cost);
    }
}

/*
    
*/