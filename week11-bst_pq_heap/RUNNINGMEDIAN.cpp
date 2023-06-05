// https://www.acmicpc.net/problem/
// RUNNINGMEDIAN
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int c; scanf("%d", &c);
    while(c--)
    {
        int n,a,b; scanf("%d%d%d", &n, &a, &b);
        long ans=0, val=1983;
    
        priority_queue<int> _greater;
        priority_queue<int, vector<int>, greater<int> > _less;
        for(int i=0; i<n; i++)
        {
            _less.push(val);
            if(_greater.size() and _greater.top() > _less.top())
                _less.push(_greater.top()), _greater.pop();
            while(_greater.size() < _less.size())
                _greater.push(_less.top()), _less.pop();
            ans=(ans+_greater.top())%20090711;
            val=(val*a+b)%20090711;
        }
        printf("%ld\n", ans);
    }
}

/*
    _less
    5
    4

    _greater
    3
    2
    1
*/