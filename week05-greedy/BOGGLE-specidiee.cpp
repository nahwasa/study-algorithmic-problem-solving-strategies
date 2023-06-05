//
// Created by RYUNA on 2023/04/14.
//
#include <bits/stdc++.h>
using namespace std;

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

vector<vector<char>> board(5, vector<char>(5));
vector<vector<vector<int>>> dp;

int solve(int x, int y, int idx, string& word) {
    if (idx == word.size()) return 1;
    if (x < 0 || x >= 5 || y < 0 || y >= 5) return 0;
    if (board[x][y] != word[idx]) return 0;
    int& ret = dp[x][y][idx];
    if (ret != -1) return ret;
    ret = 0;
    for (int i = 0; i < 8; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        ret |= solve(nx, ny, idx + 1, word);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int c; cin >> c;
    while (c--) {
        for (int i = 0; i < 5; ++i) for (int j = 0; j < 5; ++j) cin >> board[i][j];
        int N; cin >> N;
        vector<string> words(N);
        for (int i = 0; i < N; ++i) cin >> words[i];
        for (int i = 0; i < N; ++i) {
            cout << words[i] << ' ';
            dp = vector<vector<vector<int>>>(5, vector<vector<int>>(5, vector<int>(words[i].size(), -1)));
            bool found = false;
            for (int j = 0; j < 5; ++j) {
                for (int k = 0; k < 5; ++k) {
                    if (solve(j, k, 0, words[i])) {
                        found = true;
                        break;
                    }
                }
                if (found) break;
            }
            if (found) cout << "YES" << '\n';
            else cout << "NO" << '\n';
        }
    }

    return 0;
}