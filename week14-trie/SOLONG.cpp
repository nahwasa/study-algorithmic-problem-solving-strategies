// https://www.acmicpc.net/problem/
// SOLONG
#include"bits/stdc++.h"
using namespace std;

struct Trie_c
{
    map<char, Trie_c*> ma;
    int auto_complete=-1;

    int insert(const string& s, size_t idx=0)
    {
        if(idx==s.length()+1)
            return 0;
        if(ma.find(s[idx]) == ma.end())
            ma[s[idx]]=new Trie_c();
        if(auto_complete==-1)
            auto_complete=s[idx];
        return ma[s[idx]]->insert(s, idx+1);
    }

    int get_min_type(const string& s, size_t idx=0)
    {
        if(idx==s.length()+1)
            return 0;
        int ret=ma[s[idx]]->get_min_type(s, idx+1);
        if(!ret and auto_complete==s[idx])
            return ret; // auto completed
        return ret+1; // or not
    }
};

int main(void)
{
#ifdef LOCAL
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--)
    {
        int n,m; cin >> n >> m;
        Trie_c trie_c;
        trie_c.auto_complete=0;
        vector<pair<int, string> > words;
        set<string> word_list;
        for(int i=0; i<n; i++)
        {
            string s; int f;
            cin >> s >> f;
            words.push_back({-f, s});
            word_list.insert(s);
        }
        sort(words.begin(), words.end());

        for(auto it : words)
            trie_c.insert(it.second);

        int ans=m-1;
        for(int i=0; i<m; i++)
        {
            string s; cin >> s;
            if(word_list.find(s) == word_list.end()) 
                ans+=s.length();
            else
            {
                int cnt=trie_c.get_min_type(s)+1;
                cnt=min(cnt, (int)s.length());
                ans+=cnt;
                #ifdef LOCAL
                    cout << s << ' ' << cnt << '\n';
                #endif
            }
        }
        cout << ans << '\n';
    }
}

/*
    
*/