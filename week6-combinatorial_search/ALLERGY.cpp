// https://www.acmicpc.net/problem/
// ALLERGY
#include"bits/stdc++.h"
using namespace std;

int sol(bitset<50>& person, bitset<50>& solution, int n, int m, vector<set<int> >& food, int init=0)
{
    static int ans;
    if(init) ans=INT32_MAX;

    // pruning
    if(solution.count() >= ans)
        return ans;

    // find the first person who cannot eat any food.
    int target=-1;
    for(int i=0; i<n; i++)
        if(person[i] == 0)
        {
            target=i;
            break;
        }
    if(target == -1)
    {
        ans=min(ans, (int)solution.count());
        return ans;
    }   

    for(int i=0; i<m; i++) // select food
    {
        if(food[i].find(target) != food[i].end()) // if target could eat the food[i]
        {
            auto bak_per=person;
            // select this food
            solution[i]=1;
            for(int it : food[i])
                person[it]=1;

            sol(person, solution, n, m, food);

            person=bak_per;
            solution[i]=0;
        }
    }

    return ans;
}

int main(void)
{
#ifdef LOCAL
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--)
    {
        int n,m; cin >> n >> m;
        vector<string> name(n);
        for(int i=0; i<n; i++)
            cin >> name[i];

        vector<set<int> > food(m);
        for(int i=0; i<m; i++)
        {
            int cnt; cin >> cnt;
            while(cnt--)
            {
                string s; cin >> s;
                food[i].insert(find(name.begin(), name.end(), s)-name.begin());
                // n-th person can eat the i-th food.
            }
        }

        // sort by size of set (some heuristic)
        sort(food.begin(), food.end(), [](set<int>& a, set<int>& b){return a.size()>b.size();});
        
        bitset<50> a, b;
        cout << sol(a, b, n, m, food, 1) << '\n';
    }
}

/*
    
*/