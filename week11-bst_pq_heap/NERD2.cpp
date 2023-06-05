// https://www.acmicpc.net/problem/
// NERD2
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int t; scanf("%d", &t);
    while(t--)
    {
        int n; scanf("%d", &n);
        map<int, int> ma;
        long ans=0;

        for(int i=0; i<n; i++)
        {
            int a,b; scanf("%d%d", &a, &b);
            ma[a]=b;
            auto it=ma.find(a);

            if(next(it) != ma.end() and next(it)->second > b) 
                ma.erase(it);
            else
            {
                while(it != ma.begin() and prev(it)->second < it->second)
                    ma.erase(prev(it));
            }
            ans+=ma.size();
        }
        printf("%ld\n", ans);
    }
}

/*
    
*/