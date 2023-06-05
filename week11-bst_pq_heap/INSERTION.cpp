// https://www.acmicpc.net/problem/
// INSERTION
#include"bits/stdc++.h"
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <class T>
using ordered_set=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
        
        ordered_set<int> os;
        vector<int> ans(n);
        for(int i=0; i<n; i++)
            os.insert(i+1);
        
        for(int i=n-1; i>=0; i--)
        {
            auto it=os.find_by_order(i-arr[i]);
            ans[i]=*it;
            os.erase(it);
        }
        
        for(int it : ans)
            printf("%d ", it);
        printf("\n");

        // ordered_set<pair<double,int> > os; // index and value
        // for(int i=0; i<n; i++)
        //     os.insert({(i+1)*100000, i+1});

        // // unused dummy nodes
        // os.insert({0, 0});
        // os.insert({n+1*100000, 0});
        
        // for(int i=n-1; i>=0; i--)
        // {
        //     // get the i-arr[i] th element and insert this between i-th and i+1-th elements
        //     auto it=os.find_by_order(i-arr[i]+1);
        //     auto tmp=it->second;
        //     os.erase(it);

        //     auto prev_idx=os.find_by_order(i)->first, next_idx=os.find_by_order(i+1)->first;
        //     os.insert({(prev_idx+next_idx)/2, tmp});

        //     #ifdef LOCAL
        //         for(auto it : os)   
        //             printf("%lf %d, ", it.first, it.second);
        //         printf("\n");
        //     #endif
        // }

        //     for(auto it : os)
        //         if(it.second) 
        //             printf("%d ", it.second);
        // printf("\n");
    }
}

/*
    1 2 3 4 5
->  1 3 4 5
->  1 3 4 5 2 

    1 2 3 4 5
->  1 3 4 5 and ans[4]=2
->  1 4 5 and ans[3]=3
...

    find_by_order(k)
    order_of_key(k) 
*/