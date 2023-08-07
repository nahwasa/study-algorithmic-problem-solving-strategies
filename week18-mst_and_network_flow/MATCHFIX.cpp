// https://www.acmicpc.net/problem/
// MATCHFIX
#include"bits/stdc++.h"
using namespace std;

class network_flow
{
    // edmonds-karp O(VE^2)
    private:
        struct edge
        {
            int from, to, capacity, flow=0;
            edge* reverse_edge=nullptr;
            edge(int f, int t, int c) : from(f), to(t), capacity(c) {}
            inline int residual(void)
            {
                return capacity-flow;
            }
            inline void add_flow(int amount)
            {
                flow+=amount;
                reverse_edge->flow-=amount;
            }
        };
        vector<vector<edge*> > graph;
    public:
        network_flow(int size)
        {
            graph.assign(size, vector<edge*>());
        }
        void add_edge(int from, int to, int capa)
        {
            edge* e1=new edge(from, to, capa);
            edge* e2=new edge(to, from, 0);
            e1->reverse_edge=e2, e2->reverse_edge=e1;
            graph[from].push_back(e1);
            graph[to].push_back(e2);
        }
        int find_flow(int from, int to)
        {
            int ret=0;
            while(true)
            {
                queue<int> q;
                vector<edge*> prev(graph.size(), nullptr);
                q.push(from);
                while(!q.empty() and !prev[to])
                {
                    int now=q.front(); q.pop();
                    for(edge* next : graph[now])
                        if(!prev[next->to] and next->residual())
                            q.push(next->to), prev[next->to]=next;
                }
                if(!prev[to]) break;

                int min_flow=INT32_MAX;
                for(int i=to; i!=from; i=prev[i]->from)
                    min_flow=min(min_flow, prev[i]->residual());
                for(int i=to; i!=from; i=prev[i]->from)
                    prev[i]->add_flow(min_flow);
                ret+=min_flow;
            }
            return ret;
        }
};

int decision(int mid, vector<int>& arr, vector<pair<int,int> >& match)
{
    for(int i=1; i<arr.size(); i++)
        if(arr[i]>=mid) return 0;

    int n=arr.size(), m=match.size();
    network_flow flow(n+m+2); // 0~n-1, match n~n+m-1, start n+m, end n+m+1
    const int start=n+m, end=n+m+1;
    for(int i=n; i<=n+m-1; i++)
        flow.add_edge(start, i, 1);
    for(int i=n; i<=n+m-1; i++)
    {
        int match_idx=i-n;
        flow.add_edge(i, match[match_idx].first, 1);
        flow.add_edge(i, match[match_idx].second, 1);
    }
    flow.add_edge(0, end, mid-arr[0]);
    for(int i=1; i<n; i++)
        flow.add_edge(i, end, mid-arr[i]-1); // possible win count
    return flow.find_flow(start, end)==m;
}

int main(void)
{
#ifdef LOCAL
#endif
    int t; scanf("%d", &t);
    while(t--)
    {
        int n,m; scanf("%d%d", &n, &m);
        vector<int> arr(n);
        for(int i=0; i<n; i++)
            scanf("%d", &arr[i]);
        vector<pair<int,int> > match(m);
        int match_0_cnt=0;
        for(int i=0; i<m; i++)
            scanf("%d%d", &match[i].first, &match[i].second), match_0_cnt+=(!match[i].first|!match[i].second);
        
        int flag=0;
        for(int i=arr[0]; i<=arr[0]+match_0_cnt; i++)
            if(decision(i, arr, match))
            {
                flag=printf("%d\n", i);
                break;
            }
        if(!flag) printf("-1\n");
    }
}

/*
    
*/