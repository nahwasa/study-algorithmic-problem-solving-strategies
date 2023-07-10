#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int N, M;
vector<vector<int>> grid;
vector<tuple<int, int, int>> edges;
vector<int> link, set_size;

int find_islands() {
    vector visited(N, vector<bool>(M));
    int island_count = 0;
    for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) {
        if (!grid[i][j] || visited[i][j]) continue;
        ++island_count;
        queue<pair<int, int>> q; q.emplace(i, j);
        visited[i][j] = true;
        grid[i][j] = island_count;
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            for (int k = 0; k < 4; ++k) {
                int nx = x + dx[k], ny = y + dy[k];
                if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                if (!grid[nx][ny] || visited[nx][ny]) continue;
                q.emplace(nx, ny);
                visited[nx][ny] = true;
                grid[nx][ny] = island_count;
            }
        }
    }
    return island_count;
}

void find_distance(int num) {
    for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) {
        if (!grid[i][j]) continue;
        for (int k = 0; k < 4; ++k) {
            int x = i, y = j, d = 0;
            while (true) {
                x += dx[k], y += dy[k];
                if (x < 0 || x >= N || y < 0 || y >= M) break;
                if (grid[x][y] == grid[i][j]) break;
                if (grid[x][y] != 0) {
                    if (d > 1) edges.emplace_back(d, grid[i][j], grid[x][y]);
                    break;
                }
                ++d;
            }
        }
    }
}

int find(int x) {
    while (x != link[x]) x = link[x];
    return x;
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (set_size[a] < set_size[b]) swap(a, b);
    set_size[a] += set_size[b];
    link[b] = a;
}

int find_minimum() {
    sort(edges.begin(), edges.end());
    int ans = 0;
    for (auto [C, A, B] : edges) {
        if (find(A) != find(B)) {
            unite(A, B);
            ans += C;
        }
    }
    return ans;
}

bool is_possible(int island_count) {
    int max_set_size = 0;
    for (auto i : set_size) max_set_size = max(max_set_size, i);
    return max_set_size == island_count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    grid.assign(N, vector<int>(M));
    for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) cin >> grid[i][j];
    int island_count = find_islands();
    find_distance(island_count);
    link.resize(island_count + 1);
    set_size.resize(island_count + 1);
    for (int i = 1; i <= island_count; ++i) {
        link[i] = i;
        set_size[i] = 1;
    }
    int mn = find_minimum();
    bool poss = is_possible(island_count);
    cout << (poss ? mn : -1);

    return 0;
}