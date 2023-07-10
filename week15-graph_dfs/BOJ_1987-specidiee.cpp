#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int R, C;
vector<vector<int>> arr;

int dfs(int x, int y, int vis) {
    if (vis & (1 << arr[x][y])) {
        return __builtin_popcount(vis);
    }
    vis |= 1 << arr[x][y];
    int ans = 0;
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
        ans = max(ans, dfs(nx, ny, vis));
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> R >> C;
    arr.assign(R, vector<int>(C));
    for (int i = 0; i < R; ++i) for (int j = 0; j < C; ++j) {
        char c; cin >> c;
        arr[i][j] = c - 'A';
    }
    cout << dfs(0, 0, 0);

    return 0;
}