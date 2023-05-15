// https://www.acmicpc.net/problem/
// JOSEPHUS
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int t; scanf("%d", &t);
    auto next=[](list<int>::iterator it, list<int>& lst){
        it++;
        if(it == lst.end())
            it=lst.begin();
        return it;
    };
    while(t--)
    {
        int n,k; scanf("%d%d", &n, &k);
        list<int> lst;
        lst.assign(n-1, 0);
        iota(lst.begin(), lst.end(), 1);

        auto it=lst.begin();
        while(lst.size() != 2)
        {
            for(int i=0; i<k-1; i++)
                it=next(it, lst);
            auto tmp=next(it, lst);
            lst.erase(it);
            it=tmp;
        }

        int a=*it, b=*next(it, lst);
        if(a>b) swap(a,b);
        printf("%d %d\n", a+1, b+1);
    }
}