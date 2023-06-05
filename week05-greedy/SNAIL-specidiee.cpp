//
// Created by RYUNA on 2023/04/16.
//
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<double>> dp;

double solve(int days, int climbed) {
    if (days == m) {
        if (climbed >= n) return 1;
        else return 0;
    }
    double& ret = dp[days][climbed];
    if (ret != -1) return ret;
    return ret = solve(days + 1, climbed + 2) * 0.75
                 + solve(days + 1, climbed + 1) * 0.25;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int c; cin >> c;
    while (c--) {
        cin >> n >> m;
        dp = vector<vector<double>>(m, vector<double>(max(2 * m, n) + 1, -1));
        double ans = solve(0, 0);
        cout << fixed << setprecision(10) << ans << '\n';
    }

    return 0;
}