#include <bits/stdc++.h>
using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, ans = 0; cin >> N >> M;
    vector board(N, vector<int>(M));
    for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) cin >> board[i][j];
    while (++ans) {
        vector next(board);
        queue<pair<int, int>> q; q.emplace(0, 0);
        vector visited(N, vector<bool>(M));
        visited[0][0] = true;
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                if (visited[nx][ny]) {
                    next[nx][ny] = 0;
                    continue;
                }
                if (!board[nx][ny]) q.emplace(nx, ny);
                visited[nx][ny] = true;
            }
        }
        bool finished = true;
        for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) {
            if (next[i][j]) {
                finished = false;
                break;
            }
        }
        if (finished) break;
        else board = next;
    }
    cout << ans;

    return 0;
}