// https://www.acmicpc.net/problem/
// NH
// INCOMPLETED
#include"bits/stdc++.h"
using namespace std;

struct Aho
{
    static Aho* root;
    map<char, Aho*> next;
    vector<string> searched;
    Aho* failure;
    Aho() {}
    Aho(int) { Aho::root=this; }
    ~Aho()
    {
        for(auto [c, n] : next)
            delete n;
    }

    void insert(const string& s, size_t idx=0)
    {
        char nc=s[idx];
        if(nc=='\0')
        {
            searched.push_back(s);
            return;
        }
        else if(!next[nc]) 
            next[nc]=new Aho();
        next[nc]->insert(s, idx+1);
    }
    int check(const string& s, size_t idx=0)
    {
        int nc=s[idx];
        if(searched.size()) return 1;
        if(nc=='\0') return 0;
        if(this!=Aho::root and next.find(nc) == next.end())
            return failure->check(s, idx);
        if(next.find(nc) != next.end())
            return next[nc]->check(s, idx+1);
        return check(s, idx+1);
    }
    // vector<string> find(const string& s, size_t idx=0) {}
    void get_failure()
    {
        root->failure=root;
        queue<Aho*> q;

        for(auto [c, n] : root->next)
            n->failure=root, q.push(n);
        while(q.size())
        {
            Aho* curr=q.front();
            q.pop();

            for(auto [c, n] : curr->next)
            {
                Aho* dest=curr->failure;
                while(dest != root and dest->next.find(c) == dest->next.end())
                    dest=dest->failure;
                if(dest->next.find(c) != dest->next.end())
                    dest=dest->next[c];
                n->failure=dest;

                n->searched.insert(n->searched.end(), n->failure->searched.begin(), n->failure->searched.end());
                q.push(n);
            }
        }
    }
};
Aho* Aho::root=0;

int get_all(int remain, Aho* node, int init=0)
{
    static map<pair<int, Aho*>, int> memo;
    if(init) memo=map<pair<int, Aho*>, int>();

    if(!remain) return node->searched.size();
    if(memo.find({remain, node}) != memo.end())
        return memo[{remain, node}];

    int ret=node->searched.size();
    for(int nc='a'; nc<='z'; nc++)
    {
        if(node!=Aho::root and node->next.find(nc) == node->next.end())
            ret=(ret+get_all(remain, node->failure))%10007;
        else if(node->next.find(nc) != node->next.end())
            ret=(ret+get_all(remain-1, node->next[nc]))%10007;
        else
            ret=(ret+get_all(remain-1, node))%10007; // is root?   
    }
    return memo[{remain, node}]=ret;
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
        Aho* aho=new Aho(1);

        while(m--)
        {
            string s; cin >> s;
            aho->insert(s);
        }
        aho->get_failure();

        int ans=1;
        for(int i=0; i<n; i++)
            ans=(ans*26)%10007;
        
        cout << (ans+10007-get_all(n, aho, 1))%10007 << '\n';
        delete aho;
    }
}

/*
    
*/ 