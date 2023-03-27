// https://www.acmicpc.net/problem/
// 2023-03-27 17:55:10
#include"bits/stdc++.h"
using namespace std;

int get_fence_area(int s, int e, vector<int>& arr)
{
    if(s==e)
        return arr[s];

    int mid=(s+e)/2;
    int tmp_ans=arr[mid]; // the answer includes arr[mid]
    int l=mid, r=mid, height=arr[mid];
    while(l!=s or r!=e)
    {
        if(l!=s and r!=e)
        {
            if(arr[l-1] > arr[r+1])
                height=min(arr[--l], height);
            else
                height=min(arr[++r], height);
        }
        else if(l==s)
            height=min(arr[++r], height);
        else
            height=min(arr[--l], height);
        tmp_ans=max(height*(r-l+1), tmp_ans);
    }

    return max({tmp_ans, get_fence_area(s, mid, arr), get_fence_area(mid+1, e, arr)});
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
        for(int i=0; i<n; i++)
            scanf("%d", &arr[i]);
        
        printf("%d\n", get_fence_area(0, n-1, arr));
    }
}

/*
    
*/