//
// Created by RYUNA on 2023/04/17.
//
#include <bits/stdc++.h>
using namespace std;

typedef pair<float, int> pfi;
typedef long long ll;
struct question {
    int m, p, r;
    bool operator>(const question& q) const {
        return (float)p / r > (float)q.p / q.r;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, T; cin >> N >> T;
    vector<question> q(N);
    for (int i = 0; i < N; ++i) cin >> q[i].m;
    for (int i = 0; i < N; ++i) cin >> q[i].p;
    for (int i = 0; i < N; ++i) cin >> q[i].r;
    sort(q.begin(), q.end(), greater<>());
    vector<vector<ll>> dp(N+1, vector<ll>(T+1));
    for (int i = 0; i < N; ++i) for (ll j = 1; j <= T; ++j) {
            ll points = q[i].m - j * q[i].p;
            ll knapsack = (q[i].r <= j) ? (dp[i][j - q[i].r] + points) : 0;
            dp[i+1][j] = max(dp[i][j], knapsack);
        }
    ll ans = 0;
    for (int i = 1; i <= T; ++i) ans = max(ans, dp[N][i]);
    cout << ans;

    return 0;
}