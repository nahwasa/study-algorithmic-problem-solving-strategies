// https://www.acmicpc.net/problem/
// 2023-03-27 17:40:01
#include"bits/stdc++.h"
using namespace std;

pair<string, int> reverse_quadtree(const string& s)
{
    if(s.size()==1)
        return {s, 1};
    
    if(s[0]=='x')
    {
        // divide to four piece
        int prev=1;
        auto s1=reverse_quadtree(s.substr(prev));
        prev+=s1.second;
        auto s2=reverse_quadtree(s.substr(prev));
        prev+=s2.second;
        auto s3=reverse_quadtree(s.substr(prev));
        prev+=s3.second;
        auto s4=reverse_quadtree(s.substr(prev));
        prev+=s4.second;
        
        return {'x'+s3.first+s4.first+s1.first+s2.first, prev};
    }
    else
        return {s.substr(0, 1), 1};
}

int main(void)
{
#ifdef LOCAL
#endif
    int t; scanf("%d", &t);
    while (t--)
    {
        string s; cin >> s;
        cout << reverse_quadtree(s).first << '\n';
    }    
}

/*
    
*/