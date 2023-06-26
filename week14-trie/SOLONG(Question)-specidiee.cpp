#include <bits/stdc++.h>
using namespace std;

int toNum(char c) {
    return c - 'A';
}

struct vertex {
    char alphabet;
    int usage;
    vector<vertex*> child;
    vertex(char a): alphabet(a), usage(0) {
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
    void insert(string word, int usage) {
        vertex* cur = root;
        for (int i = 0; i < word.size(); ++i) {
            int alphaNum = toNum(word[i]);
            if (cur->child[alphaNum] == nullptr) {
                cur->child[alphaNum] = new vertex(word[i]);
            }
            cur = cur->child[alphaNum];
        }
        cur->usage = usage;
    }
    bool search(string word) {
        vertex* cur = root;
        for (int i = 0; i < word.size(); ++i) {
            int alphaNum = toNum(word[i]);
            if (cur->child[alphaNum] == nullptr) {
                return false;
            }
            cur = cur->child[alphaNum];
        }
        return cur->usage > 0;
    }
    int autocomplete(string word) {
        if (!search(word)) return word.size();
        // TODO
        return 0;
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
        int ans = 0;
        for (int i = 0; i < M; ++i) {
            string word; cin >> word;
            ans += trie.autocomplete(word);
            if (i != M - 1) ans += 1;
        }
        cout << ans << '\n';
    }

    return 0;
}