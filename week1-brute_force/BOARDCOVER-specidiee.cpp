#include <bits/stdc++.h>
using namespace std;

int dx[4][2] = {{0, 1}, {0, 1}, {1, 1}, {1, 1}};
int dy[4][2] = {{1, 0}, {1, 1}, {0, 1}, {-1, 0}};

int H, W, ans;
vector<vector<bool>> board;

void cover(int toCover) {
    if (toCover == 0) {
        ++ans;
        return;
    }
    int start = 0;
    while (board[start / W][start % W]) ++start;
    int i = start / W, j = start % W;
    for (int k = 0; k < 4; ++k) {
        if (i + dx[k][0] < 0 || i + dx[k][0] >= H || j + dy[k][0] < 0 || j + dy[k][0] >= W) continue;
        if (i + dx[k][1] < 0 || i + dx[k][1] >= H || j + dy[k][1] < 0 || j + dy[k][1] >= W) continue;
        if (board[i + dx[k][0]][j + dy[k][0]] || board[i + dx[k][1]][j + dy[k][1]]) continue;
        board[i][j] = true;
        board[i + dx[k][0]][j + dy[k][0]] = true;
        board[i + dx[k][1]][j + dy[k][1]] = true;
        cover(toCover - 1);
        board[i][j] = false;
        board[i + dx[k][0]][j + dy[k][0]] = false;
        board[i + dx[k][1]][j + dy[k][1]] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int C; cin >> C;
    while (C--) {
        cin >> H >> W;
        board = vector<vector<bool>>(H, vector<bool>(W));
        int whites = 0;
        for (int i = 0; i < H; ++i) for (int j = 0; j < W; ++j) {
            char c; cin >> c;
            board[i][j] = c == '#';
            if (c == '.') ++whites;
        }
        ans = 0;
        if (whites % 3 == 0) cover(whites / 3);
        cout << ans << "\n";
    }

    return 0;
}
