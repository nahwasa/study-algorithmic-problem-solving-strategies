// https://www.acmicpc.net/problem/
// NH
#include"bits/stdc++.h"
using namespace std;

struct Aho
{
    static Aho* root;
    // map<char, Aho*> next;
    vector<Aho*> next;
    vector<string> searched;
    vector<Aho*> next_memo;
    Aho* failure;
    Aho() { next.assign(26, nullptr); next_memo.assign(26, nullptr); }
    Aho(int) { Aho::root=this; next.assign(26, nullptr); next_memo.assign(26, nullptr); }
    ~Aho()
    {
        // for(auto [c, n] : next)
            // delete n;
        for(int i=0; i<26; i++)
            if(next[i]) delete next[i];
    }

    void insert(const string& s, size_t idx=0)
    {
        char nc=s[idx]-'a';
        if(nc=='\0'-'a')
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
        int nc=s[idx]-'a';
        if(searched.size()) return 1;
        if(nc=='\0') return 0;
        // if(this!=Aho::root and next.find(nc) == next.end())
        if(this!=Aho::root and !next[nc])
            return failure->check(s, idx);
        // if(next.find(nc) != next.end())
        if(next[nc])
            return next[nc]->check(s, idx+1);
        return check(s, idx+1);
    }
    // vector<string> find(const string& s, size_t idx=0) {}
    void get_failure()
    {
        root->failure=root;
        queue<Aho*> q;

        // for(auto [c, n] : root->next)
            // n->failure=root, q.push(n);
        for(int i=0; i<26; i++)
            if(root->next[i])
                root->next[i]->failure=root, q.push(root->next[i]);

        while(q.size())
        {
            Aho* curr=q.front();
            q.pop();

            // for(auto [c, n] : curr->next)
            for(int c=0; c<26; c++)
            {
                if(!curr->next[c]) continue;

                Aho* dest=curr->failure;
                // while(dest != root and dest->next.find(c) == dest->next.end())
                while(dest != root and !dest->next[c])
                    dest=dest->failure;
                // if(dest->next.find(c) != dest->next.end())
                if(dest->next[c])
                    dest=dest->next[c];
                
                Aho* n=curr->next[c];
                n->failure=dest;
                n->searched.insert(n->searched.end(), n->failure->searched.begin(), n->failure->searched.end());
                q.push(n);
            }
        }
    }
};
Aho* Aho::root=0;

int get_cnt(int remain)
{
    static vector<int> memo(101, -1);
    if(memo[remain] != -1) return memo[remain];
    if(remain==0) return 1;
    return memo[remain]=26*get_cnt(remain-1)%10007;
}

int get_all(int remain, Aho* node, int init=0)
{
    static map<pair<int, Aho*>, int> memo;
    if(init) memo=map<pair<int, Aho*>, int>();

    if(node->searched.size()) return get_cnt(remain); 
    if(!remain) return 0; // possible to make 
    if(memo.find({remain, node}) != memo.end())
        return memo[{remain, node}];

    int ret=0;
    for(int nc='a'-'a'; nc<='z'-'a'; nc++)
    {
        if(node->next_memo[nc]) ret=(ret+get_all(remain-1, node->next_memo[nc]))%10007;
        else
        {
            Aho* next_addr=nullptr;
            if(node!=Aho::root and !node->next[nc])
            {
                Aho* cur=node;
                while(cur!=Aho::root and !cur->next[nc])
                    cur=cur->failure;
                if(!cur->next[nc])
                    next_addr=cur;
                else
                    next_addr=cur->next[nc];
            }
            else if(node->next[nc])
                next_addr=node->next[nc];
            else
                next_addr=node; // is root?
            
            node->next_memo[nc]=next_addr;
            ret=(ret+get_all(remain-1, next_addr))%10007;
        }
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
        
        cout << (get_cnt(n)+10007-get_all(n, aho, 1))%10007 << '\n';
        delete aho;
    }
}

/*
    
*/ 
