// https://www.acmicpc.net/problem/
// 2023-04-02 21:29:38
#include"bits/stdc++.h"
using namespace std;

int get_diff(string&& s)
{
// 모든 숫자가 같을 때 (예: 333, 5555) 난이도: 1
{
    int flag=1;
    for(int i=1; i<s.length(); i++)
        if(s[i]!=s[0]) flag=0;
    if(flag) return 1;
}
// 숫자가 1씩 단조 증가하거나 단조 감소할 때 (예: 23456, 3210) 난이도: 2
{
    int flag=1, prev=s[0];
    for(int i=1; i<s.length(); i++) 
    {
        if(s[i]!=prev+1) flag=0;
        prev=s[i];
    }
    if(flag) return 2;
    flag=1, prev=s[0];
    for(int i=1; i<s.length(); i++) 
    {
        if(s[i]!=prev-1) flag=0;
        prev=s[i];
    }
    if(flag) return 2;
}
// 두 개의 숫자가 번갈아 가며 출현할 때 (예: 323, 54545) 난이도: 4
{
    int flag=1, even=s[0], odd=s[1];
    for(int i=2; i<s.length(); i++)
        if((i&1 and odd!=s[i]) or ((i&1)==0 and even!=s[i])) flag=0;
    if(flag) return 4;
}
// 숫자가 등차 수열을 이룰 때 (예: 147, 8642) 난이도: 5
{
    int flag=1, diff=s[1]-s[0];
    for(int i=2; i<s.length(); i++)
        if(s[i]-s[i-1]!=diff) flag=0;
    if(flag) return 5;
}
// 그 외의 경우 난이도: 10
    return 10;
}

int get_min_dif(string& s, int idx, int init=0)
{
    static vector<int> memo;
    if(init)
        memo=vector<int>(s.length()+1, -1);
    if(idx==s.length())
        return 0;
    if(memo[idx] != -1)
        return memo[idx];

    int ret=INT32_MAX/2;
    for(int i=3; i<=5; i++)
        if(idx+i <= s.length())
        ret=min(ret, get_min_dif(s, idx+i)+get_diff(s.substr(idx, i)));
    return memo[idx]=ret;
}

int main(void)
{
#ifdef LOCAL
#endif
    int t; scanf("%d", &t);
    while(t--)
    {
        string s; cin >> s;
        printf("%d\n", get_min_dif(s, 0, 1));
    }
}   

/*

*/