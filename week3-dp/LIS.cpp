// https://www.acmicpc.net/problem/
// 2023-04-02 20:13:11
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
        vector<int> arr(n);
        for(int i=0; i<n; i++) 
            scanf("%d", &arr[i]);
        
        vector<int> lis;
        for(int i=0; i<n; i++)
        {
            auto it=lower_bound(lis.begin(), lis.end(), arr[i]);
            if(it==lis.end())
                lis.push_back(arr[i]);
            else
                *it=arr[i];
        }
        printf("%lu\n", lis.size());
    }
}

/*
    why no dpdp
*/