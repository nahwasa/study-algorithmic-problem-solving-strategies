#include <bits/stdc++.h>
using namespace std;

vector<int> dp;
vector<vector<int>> adj;

void dfs(int s, int e = 0) {
    dp[s] = 1;
    for (int u : adj[s]) {
        if (u != e) {
            dfs(u, s);
            dp[s] += dp[u];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, R, Q; cin >> N >> R >> Q;
    adj.resize(N + 1);
    for (int i = 1; i < N; ++i) {
        int U, V; cin >> U >> V;
        adj[U].push_back(V);
        adj[V].push_back(U);
    }
    dp.resize(N);
    dfs(R);
    for (int i = 0; i < Q; ++i) {
        int U; cin >> U;
        cout << dp[U] << "\n";
    }

    return 0;
}