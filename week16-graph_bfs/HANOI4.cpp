// https://www.acmicpc.net/problem/
// HANOI4
#include"bits/stdc++.h"
using namespace std;

inline int vec_to_int(const vector<int>& arr)
{
    int ret=0;
    for(int i=0; i<arr.size(); i++)
        ret=(ret<<2) + arr[i];
    return ret;
}

inline vector<int> int_to_vec(int mask, int siz)
{
    vector<int> ret(siz);
    while(siz--)
    {
        ret[siz]=mask%4;
        mask>>=2;
    }
    return ret;
}

int main(void)
{
#ifdef LOCAL
#endif
    int t; scanf("%d", &t);
    while(t--)
    {
        int n; scanf("%d", &n);
        vector<int> arr(n);
        for(int i=0; i<4; i++)
        {
            int a; scanf("%d", &a);
            while(a--)
            {
                int b; scanf("%d", &b);
                arr[b-1]=i;
            }
        }

        struct st
        {   
            int first, second, third;
        };
        queue<st> q;
        vector<pair<int, int> > visited(1<<24, {-1, -1});

        q.push({vec_to_int(vector<int>(n, 3)), 0, 0});
        visited[vec_to_int(vector<int>(n, 3))]={0, 0};

        q.push({vec_to_int(arr), 0, 1});
        visited[vec_to_int(arr)]={0, 1};

        while(q.size())
        {
            vector<int> now=int_to_vec(q.front().first, n);
            int cnt=q.front().second;
            int type=q.front().third;
            q.pop(); 

            // get movables
            vector<int> top(4, 100);
            for(int i=0; i<n; i++)
                top[now[i]]=min(top[now[i]], i);
            
            // move i to j
            for(int i=0; i<4; i++)
                for(int j=0; j<4; j++)
                    if(top[i] < top[j])
                    {
                        now[top[i]]=j;
                        int next_mask=vec_to_int(now);
                        now[top[i]]=i;

                        if(visited[next_mask] == make_pair(-1, -1))
                        {
                            visited[next_mask]={cnt+1, type};
                            q.push({next_mask, cnt+1, type});
                        }
                        else if(visited[next_mask].second != type)
                        {
                            printf("%d\n", visited[next_mask].first+cnt+1);
                            goto end;
                        }
                    }
        }
        end:
            continue;
    }
}

/*
    
*/