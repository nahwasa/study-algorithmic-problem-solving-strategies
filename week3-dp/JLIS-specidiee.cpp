//
// Created by RYUNA on 2023/04/03.
//
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m;
vector<int> A, B;
vector<vector<int>> dp;

int solve(int i, int j) {
    int& ret = dp[i+1][j+1];
    if (ret != -1) return ret;
    ret = 2;
    ll a = i == -1 ? (ll)-1e18 : A[i];
    ll b = j == -1 ? (ll)-1e18 : B[j];
    ll max_val = max(a, b);
    for (int k = i + 1; k < n; ++k) {
        if (A[k] > max_val) ret = max(ret, 1 + solve(k, j));
    }
    for (int k = j + 1; k < m; ++k) {
        if (B[k] > max_val) ret = max(ret, 1 + solve(i, k));
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int c; cin >> c;
    while (c--) {
        cin >> n >> m;
        A = vector<int>(n);
        B = vector<int>(m);
        for (int i = 0; i < n; ++i) cin >> A[i];
        for (int i = 0; i < m; ++i) cin >> B[i];
        dp = vector<vector<int>>(n + 1, vector<int>(m + 1, -1));
        cout << solve(-1, -1) - 2 << '\n';
    }

    return 0;
}