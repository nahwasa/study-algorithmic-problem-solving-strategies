#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited, fan;

void dfs(int u, bool met_fan = false) {
    if (!met_fan && adj[u].empty()) {
        cout << "yes";
        exit(0);
    }
    for (int v : adj[u]) {
        dfs(v, met_fan || fan[v]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    adj.assign(N + 1, vector<int>());
    for (int i = 0; i < M; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }
    int S; cin >> S;
    fan.resize(N + 1);
    for (int i = 0; i < S; ++i) {
        int u; cin >> u;
        fan[u] = true;
    }
    visited.resize(N + 1);
    dfs(1, fan[1]);
    cout << "Yes";

    return 0;
}