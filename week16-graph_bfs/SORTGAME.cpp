// https://www.acmicpc.net/problem/
// SORTGAME
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    map<vector<short>, int> preprocessed;
    for(int n=1; n<9; n++)
    {
        vector<short> arr(n);
        map<vector<short>, int> visited;
        iota(arr.begin(), arr.end(), 0);
        queue<pair<int, vector<short> > > q; 
        q.push({0, arr});
        visited[arr]=0;
        while(q.size())
        {
            int cnt=q.front().first;
            auto now=q.front().second;
            q.pop();

            for(int i=0; i<n; i++)
                for(int j=i+2; j<=n; j++)
                {
                    reverse(now.begin()+i, now.begin()+j);
                    if(visited.find(now) == visited.end())
                        visited[now]=cnt+1, q.push({cnt+1, now});
                    reverse(now.begin()+i, now.begin()+j);
                }
        }  
        preprocessed.insert(visited.begin(), visited.end());
    }

    int t; scanf("%d", &t);
    while(t--)
    {
        int n; scanf("%d", &n);

        vector<int> arr(n);
        for(int i=0; i<n; i++)
            scanf("%d", &arr[i]);

        vector<int> tmp(arr.begin(), arr.end());
        vector<short> compressed(n);
        sort(tmp.begin(), tmp.end());
        for(int i=0; i<n; i++)
            compressed[i]=find(arr.begin(), arr.end(), tmp[i])-arr.begin();
        
        printf("%d\n", preprocessed[compressed]);
    }
}

/*
    
*/