#include <bits/stdc++.h>
using namespace std;

int toNum(char c) {
    return c - 'A';
}

struct word {
    string str;
    int usage;
    word(string s, int u): str(s), usage(u) {}
    bool operator<(const word& w) const {
        if (usage == w.usage) return str > w.str;
        return usage < w.usage;
    }
};

struct vertex {
    char alphabet;
    priority_queue<word> pq;
    vector<vertex*> child;
    vertex(char a): alphabet(a) {
        child.assign(26, nullptr);
    }
};

class Trie {
private:
    vertex* root;
public:
    Trie() {
        root = new vertex(' ');
    }
    void insert(string str, int usage) {
        vertex* cur = root;
        for (int i = 0; i < str.size(); ++i) {
            int alphaNum = toNum(str[i]);
            if (cur->child[alphaNum] == nullptr) {
                cur->child[alphaNum] = new vertex(str[i]);
            }
            cur = cur->child[alphaNum];
            cur->pq.emplace(str, usage);
        }
    }
    int search(string str) {
        vertex* cur = root;
        for (int i = 0; i < str.size(); ++i) {
            int alphaNum = toNum(str[i]);
            if (cur->child[alphaNum] == nullptr) {
                return str.size();
            }
            cur = cur->child[alphaNum];
            if (cur->pq.top().str == str) {
                return min(i + 2, (int)str.size());
            }
        }
        return str.size();
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int C; cin >> C;
    while (C--) {
        int N, M; cin >> N >> M;
        Trie trie;
        for (int i = 0; i < N; ++i) {
            string word; int usage;
            cin >> word >> usage;
            trie.insert(word, usage);
        }
        int ans = M - 1;
        for (int i = 0; i < M; ++i) {
            string word; cin >> word;
            ans += trie.search(word);
        }
        cout << ans << '\n';
    }

    return 0;
}