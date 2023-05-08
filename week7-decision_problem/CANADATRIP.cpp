// https://www.acmicpc.net/problem/
// CANADATRIP
#include"bits/stdc++.h"
using namespace std;

int check(int mid, vector<tuple<int, int, int> >& arr, int k)
{
    long cnt=0;
    // for(auto& [loca, start, duration] : arr)
    for(int i=0; i<arr.size(); i++)
    {
        int loca=get<0>(arr[i]), start=get<1>(arr[i]), duration=get<2>(arr[i]); 
        int range=min(mid, loca) - (loca-start);
        if(range < 0) continue;
        cnt+=range / duration + 1;
    }
    return cnt >= k;
}
// 1 5
// 26 17 4
// 012345678901234567890123456
// ----------b---a---a---a---c
//           12345678901234567
// b -> range_start = loca - start
// c -> range_end = min(mid, loca);
// 16 / 4 -> 4
// 13 / 4 -> 3.x
// 12 / 4 -> 3
// -> ceil(range / duration) 

int main(void)
{
#ifdef LOCAL
#endif
    int t; scanf("%d", &t);
    while(t--)
    {
        int n, k; scanf("%d%d", &n, &k);
        vector<tuple<int, int, int> > arr(n);
        for(int i=0; i<n; i++)
        {
            int a,b,c; scanf("%d%d%d", &a, &b, &c);
            arr[i]=tuple<int,int,int>(a,b,c);
        }

        int lo=0, hi=10000000, ans=0;
        while(lo<=hi)
        {
            int mid=lo+hi>>1;
            if(check(mid, arr, k))
                hi=mid-1, ans=mid;
            else
                lo=mid+1;
        }
        printf("%d\n", ans);
    }
}

/*
    
*/