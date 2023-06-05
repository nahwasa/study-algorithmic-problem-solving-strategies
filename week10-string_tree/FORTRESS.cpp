// https://www.acmicpc.net/problem/
// FORTRESS
#include"bits/stdc++.h"
using namespace std;

struct s
{
    int x,y,r;
    bool operator<(const s& a) const
    {
        return r<a.r;
    }
};

inline int distof(int a, int b, int x, int y)
{
    return (a-x)*(a-x)+(b-y)*(b-y);
}

int check_inside(const s& a, const s& b)
{
    // if a is in b, return 1
    return distof(a.x, a.y, b.x, b.y) <= b.r*b.r;
}

// dist, vertex
pair<int,int> dfs(int now, int prev, int dist, vector<vector<int> >& graph, int init=0)
{
    if(graph[now].size()==1 and graph[now].front() == prev)
        return {dist, now};
    
    pair<int,int> ret={-1, -1}; 
    for(auto next : graph[now])
        if(next!=prev)
        ret=max(ret, dfs(next, now, dist+1, graph));
    return ret;
}

int diameter(vector<vector<int> >& graph)
{
    int fartest=dfs(0, -1, 0, graph, 1).second;
    return dfs(fartest, -1, 0, graph, 1).first;
}

int main(void)
{
#ifdef LOCAL
#endif
    int t; scanf("%d", &t);
    while(t--)
    {
        int n; scanf("%d", &n);
        vector<s> arr(n);
        for(int i=0; i<n; i++)
            scanf("%d%d%d", &arr[i].x, &arr[i].y, &arr[i].r);
        sort(arr.begin(), arr.end());

        if(n==1) 
        {
            printf("0\n");
            continue;
        }

        vector<vector<int> > graph(n+1);
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
                if(check_inside(arr[i], arr[j]))
                {
                    graph[j].push_back(i);
                    graph[i].push_back(j);
                    break;
                }
        }

        // tree's diameter
        printf("%d\n", diameter(graph));
    }
}

/*
    
*/