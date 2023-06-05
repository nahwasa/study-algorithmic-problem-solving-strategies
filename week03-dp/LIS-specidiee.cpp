//
// Created by RYUNA on 2023/04/03.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int c; cin >> c;
    while (c--) {
        int n; cin >> n;
        vector<int> seq(n), dp(n, -1), last;
        for (int i = 0; i < n; ++i) cin >> seq[i];
        for (int i = 0; i < n; ++i) {
            auto j = lower_bound(last.begin(), last.end(), seq[i]) - last.begin();
            if (j == last.size()) last.push_back(seq[i]);
            else last[j] = seq[i];
            dp[i] = (int)j + 1;
        }
        cout << last.size() << '\n';
    }

    return 0;
}