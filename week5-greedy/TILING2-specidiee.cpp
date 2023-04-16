//
// Created by RYUNA on 2023/04/16.
//
#include <bits/stdc++.h>
using namespace std;

int mod = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int c; cin >> c;
    while (c--) {
        int n; cin >> n;
        vector<int> dp(n+1);
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            dp[i] = (dp[i-1] + dp[i-2]) % mod;
        }
        cout << dp[n] << '\n';
    }

    return 0;
}