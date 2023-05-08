// https://www.acmicpc.net/problem/
// ARCTIC
#include"bits/stdc++.h"
using namespace std;

double get_dist(pair<double, double>& a, pair<double, double>& b)
{
    return (a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second);
}

int check(double mid, vector<pair<double, double> >& arr)
{
    vector<int> visited(arr.size());
    
    queue<int> q;
    visited[0]=1;
    q.push(0);
    while(q.size())
    {
        int now=q.front();
        q.pop();

        for(int i=0; i<arr.size(); i++)
            if(!visited[i] and get_dist(arr[now], arr[i]) < mid)
                visited[i]=1, q.push(i);
    }
    return accumulate(visited.begin(), visited.end(), 0) == arr.size();
}

int main(void)
{
#ifdef LOCAL
#endif
    int t; scanf("%d", &t);
    while(t--)
    {
        int n; scanf("%d", &n);
        vector<pair<double, double> > arr(n);
        for(int i=0; i<n; i++)
            scanf("%lf %lf", &arr[i].first, &arr[i].second);
        
        double lo=0, hi=2000*2000, ans=10000;
        for(int i=0; i<100; i++)
        {
            double mid=(lo+hi)/2;
            if(check(mid, arr))
                ans=hi=mid;
            else
                lo=mid;
        }
        printf("%.2lf\n", sqrt(ans));
    }

}

/*
    
*/