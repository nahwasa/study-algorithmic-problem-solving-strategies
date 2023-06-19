// https://www.acmicpc.net/problem/
// MORDOR
#include"bits/stdc++.h"
using namespace std;

template <typename T>
class seg_tree
{
    private:
        T initial={INT32_MAX, INT32_MIN};
        T base={INT32_MAX, INT32_MIN};
        inline T f(const T& a, const T& b) 
        {
            return {min(a.first, b.first), max(a.second, b.second)};
        }
        int size;
        vector<T> tree;
        T _init(const vector<T>& arr, int now, int s, int e)
        {
            if(s==e) return tree[now]=arr[s];
            else return tree[now]=f(_init(arr, now*2, s, (s+e)/2), _init(arr, now*2+1, ((s+e)/2)+1, e)); 
        }
        T _get(int l, int r, int now, int s, int e)
        {
            if(s>r or e<l) return base;
            else if(l<=s and e<=r) return tree[now];
            else return f(_get(l, r, now*2, s, (s+e)/2), _get(l, r, now*2+1, ((s+e)/2)+1, e));
        }
        T _update(int i, T v, int now, int s, int e)
        {
            if(!(s<=i and i<=e)) return tree[now];
            else if(s==e and s==i) return tree[now]=v;
            else return tree[now]=f(_update(i, v, now*2, s, (s+e)/2), _update(i, v, now*2+1, ((s+e)/2)+1, e));
        }
    public:
        seg_tree(int size)
        {
            this->size=size;
            tree.assign(size*4, initial);
        }
        T init(const vector<T>& arr, int now=0, int s=0, int e=0)
            { return now ? _init(arr, now, s, e):_init(arr, 1, 0, size-1); }
        T get(int l, int r, int now=0, int s=0, int e=0)
            { return now ? _get(l, r, now, s, e):_get(l, r, 1, 0, size-1); }
        T update(int index, T value, int now=0, int s=0, int e=0)
            { return now ? _update(index, value, now, s, e):_update(index, value, 1, 0, size-1); }
};

int main(void)
{
#ifdef LOCAL
#endif
    int t; scanf("%d", &t);
    while(t--)
    {
        int n,q; scanf("%d%d", &n, &q);
        seg_tree<pair<int,int> > seg(n);
        for(int i=0; i<n; i++)
        {
            int a; scanf("%d", &a);
            seg.update(i, {a, a});
        }
        while(q--)
        {
            int a,b; scanf("%d%d", &a, &b);
            printf("%d\n", seg.get(a, b).second-seg.get(a,b).first);
        }
    }
}

/*
    
*/
