//
// Created by RYUNA on 2023/05/01.
//
#include <bits/stdc++.h>
using namespace std;

int n, m, ans;
vector<int> chosen;
vector<vector<int>> not_allergic, friends;

void solve(int k) {
    if (k >= ans) return;
    int f = 0;
    while (f < n && chosen[f] > 0) ++f;
    if (f == n) {
        ans = k;
        return;
    }
    for (int i = 0; i < not_allergic[f].size(); ++i) {
        int x = not_allergic[f][i];
        for (int y : friends[x]) {
            ++chosen[y];
        }
        solve(k + 1);
        for (int y : friends[x]) {
            --chosen[y];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        cin >> n >> m;
        map<string, int> id;
        for (int i = 0; i < n; ++i) {
            string s; cin >> s;
            id[s] = i;
        };
        not_allergic = vector<vector<int>>(n);
        friends = vector<vector<int>>(m);
        for (int i = 0; i < m; ++i) {
            int k; cin >> k;
            while (k--) {
                string s; cin >> s;
                int x = id[s];
                friends[i].push_back(x);
                not_allergic[x].push_back(i);
            }
        }
        chosen = vector<int>(n, 0);
        ans = 1e9;
        solve(0);
        cout << ans << '\n';
    }

    return 0;
}