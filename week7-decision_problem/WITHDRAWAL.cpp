// https://www.acmicpc.net/problem/
// WITHDRAWAL
#include"bits/stdc++.h"
using namespace std;

int check(double mid, vector<pair<int, int> >& arr, int k)
{
    vector<double> tmp;
    for(int i=0; i<arr.size(); i++)
        tmp.push_back(mid*arr[i].second - arr[i].first);
    sort(tmp.begin(), tmp.end(), greater<double>());
    return accumulate(tmp.begin(), tmp.begin()+k, 0.) > 0;
}
// sum(arr.first)/sum(arr.second) < mid
// -> 0 < mid*sum(arr.second)-sum(arr.first)
// -> 0 < sum(mid * arr[i].second - arr[i].first) 이면 ok
// -> ?

int main(void)
{
#ifdef LOCAL
#endif
    int t; scanf("%d", &t);
    while(t--)
    {
        int n,k; scanf("%d%d", &n, &k);
        vector<pair<int,int> > arr(n);
        for(int i=0; i<n; i++)
            scanf("%d%d", &arr[i].first, &arr[i].second);
        
        double lo=0, hi=1, ans=1;
        for(int i=0; i<100; i++)
        {
            double mid=(lo+hi)/2;
            if(check(mid, arr, k))
                hi=mid, ans=mid;
            else
                lo=mid; 
        }
        printf("%.8lf\n", ans);
    }
}

/*
    
*/