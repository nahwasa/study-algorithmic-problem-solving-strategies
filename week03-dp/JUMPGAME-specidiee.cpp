//
// Created by RYUNA on 2023/04/03.
//
#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> board, dp;

int jump(int x, int y) {
    if (x >= n || y >= n) return 0;
    if (x == n - 1 && y == n - 1) return 1;
    int& ret = dp[x][y];
    if (ret != -1) return ret;
    return ret = (jump(x + board[x][y], y) || jump(x, y + board[x][y]));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int c; cin >> c;
    while (c--) {
        cin >> n;
        board = vector<vector<int>>(n, vector<int>(n));
        dp = vector<vector<int>>(n, vector<int>(n, -1));
        for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> board[i][j];
        cout << (jump(0, 0) ? "YES\n" : "NO\n");
    }

    return 0;
}