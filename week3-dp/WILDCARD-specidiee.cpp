//
// Created by RYUNA on 2023/04/03.
//
#include <bits/stdc++.h>
using namespace std;

string W, S;
int n;
vector<vector<int>> dp;

int solve(int w, int s) {
    if (w == W.size()) return s == S.size();
    if (s == S.size()) return W[w] == '*' && solve(w + 1, s);
    int& ret = dp[w][s];
    if (ret != -1) return ret;
    if (W[w] == '?' || W[w] == S[s]) return ret = solve(w + 1, s + 1);
    if (W[w] == '*') {
        if (solve(w + 1, s) || solve(w, s + 1)) return ret = 1;
    }
    return ret = 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int c; cin >> c;
    while (c--) {
        cin >> W >> n;
        set<string> ans;
        for (int i = 0; i < n; ++i) {
            cin >> S;
            dp = vector<vector<int>>(W.size(), vector<int>(S.size(), -1));
            if (solve(0, 0)) ans.insert(S);
        }
        for (const auto& filename : ans) cout << filename << '\n';
    }

    return 0;
}