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

int line_cnt=0;
int get_line_info_1(int x, int y, vector<vector<int> >& table, vector<vector<pair<int,int> > >& line_info, int init=0)
{
    static vector<vector<int> > visited(table.size(), vector<int>(table.size()));
    if(init) visited=vector<vector<int> > (table.size(), vector<int>(table.size()));
    if(y==table.size()) return get_line_info_1(x+1, 0, table, line_info);
    if(x==table.size()) return 0;
    if(visited[x][y]) return get_line_info_1(x, y+1, table, line_info);

    int flag=0;
    // lt to rb
    int i=x, j=y;
    while(i<table.size() and j<table.size() and table[i][j]!='*')
    {
        if(table[i][j] != '*') line_info[i][j].first=line_cnt, flag=1, visited[i][j]=1;
        i++, j++;
    }

    if(flag) line_cnt++;
    return get_line_info_1(x, y+1, table, line_info);
}
int get_line_info_2(int x, int y, vector<vector<int> >& table, vector<vector<pair<int,int> > >& line_info, int init=0)
{
    static vector<vector<int> > visited(table.size(), vector<int>(table.size()));
    if(init) visited=vector<vector<int> > (table.size(), vector<int>(table.size()));
    if(y==table.size()) return get_line_info_2(x+1, 0, table, line_info);
    if(x==table.size()) return 0;
    if(visited[x][y]) return get_line_info_2(x, y+1, table, line_info);

    int flag=0;
    // rt to lb
    int i=x, j=y;
    while(i<table.size() and 0<=j and table[i][j]!='*')
    {
        if(table[i][j] != '*') line_info[i][j].second=line_cnt, flag=1, visited[i][j]=1;
        i++, j--;
    }

    if(flag) line_cnt++;
    return get_line_info_2(x, y+1, table, line_info);
}

int main(void)
{
#ifdef LOCAL
#endif
    int t; scanf("%d", &t);
    while(t--)
    {
        int n; scanf("%d", &n);
        vector<vector<int> > table(n, vector<int>(n));
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                scanf(" %c", &table[i][j]);
        
        vector<vector<pair<int,int> > > line_info(n, vector<pair<int,int> >(n));
        get_line_info_1(0, 0, table, line_info, 1);
        int cnt_1=line_cnt;
        get_line_info_2(0, 0, table, line_info, 1);

        #ifdef LOCAL
            printf("\n");
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<n; j++)
                    printf("%02d %02d | ", line_info[i][j].first, line_info[i][j].second);
                printf("\n");
            }
        #endif
        network_flow flow(line_cnt+2);
        int start=line_cnt, end=line_cnt+1;
        for(int i=0; i<cnt_1; i++)
            flow.add_edge(start, i, 1);
        for(int i=cnt_1; i<line_cnt; i++)
            flow.add_edge(i, end, 1);
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
            {
                if(table[i][j] == '*') continue;
                flow.add_edge(line_info[i][j].first, line_info[i][j].second, 1);
            }
        printf("%d\n", flow.find_flow(start, end));
    }
}

/*
    
*/