// https://www.acmicpc.net/problem/
// 2023-04-02 19:34:44
#include"bits/stdc++.h"
using namespace std;

int dp(int i, int j, string& t, string& s, int init=0)
{
    static vector<vector<int> > memo;
    if(init==1)
        memo=vector<vector<int> >(t.size()+1, vector<int>(s.size()+1, -1));
    
    if(i==t.size() and j==s.size())
        return 1;
    else if(i>t.size() or j>s.size())
        return 0;

    if(memo[i][j] != -1)
        return memo[i][j];

    int ret=0;

    if(t[i]=='?')
        ret+=dp(i+1, j+1, t, s);
    else if(t[i]=='*')
    {
        for(int k=j; k<=s.size(); k++)
            ret+=dp(i+1, k, t, s);
    }
    else if(t[i] == s[j])
        ret+=dp(i+1, j+1, t, s);
    return memo[i][j]=!!ret;
}

int check_matched(string& target, string& s)
{
    return dp(0, 0, target, s, 1);
}

int main(void)
{
#ifdef LOCAL
#endif
    int t; scanf("%d", &t);
    while(t--)
    {
        string target; cin >> target;
        int n; cin >> n;
        vector<string> arr(n);
        for(int i=0; i<n; i++)  
            cin >> arr[i];
        
        sort(arr.begin(), arr.end());
        for(auto s : arr)
            if(check_matched(target, s))
                cout << s << '\n';
    }
}

/*
    
*/