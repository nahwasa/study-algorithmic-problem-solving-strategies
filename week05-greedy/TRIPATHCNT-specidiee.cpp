//
// Created by RYUNA on 2023/04/16.
//
#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> board, dp, cnt;

int path(int x, int y) {
    if (x == n - 1) return board[x][y];
    int& ret = dp[x][y];
    if (ret != -1) return ret;
    return ret = board[x][y] + max(path(x + 1, y), path(x + 1, y + 1));
}

int count(int x, int y) {
    if (x == n - 1) return 1;
    int& ret = cnt[x][y];
    if (ret != -1) return ret;
    ret = 0;
    if (path(x + 1, y) >= path(x + 1, y + 1)) ret += count(x + 1, y);
    if (path(x + 1, y) <= path(x + 1, y + 1)) ret += count(x + 1, y + 1);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int c; cin >> c;
    while (c--) {
        cin >> n;
        board = vector<vector<int>>(n, vector<int>(n));
        dp = vector<vector<int>>(n, vector<int>(n, -1));
        cnt = vector<vector<int>>(n, vector<int>(n, -1));
        for (int i = 0; i < n; ++i) for (int j = 0; j <= i; ++j) cin >> board[i][j];
        path(0, 0);
        cout << count(0, 0) << '\n';
    }

    return 0;
}