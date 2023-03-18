#include <bits/stdc++.h>
using namespace std;

int n, m, ans;
vector<bool> picked;
vector<vector<bool>> friendship;

void pick(int toPick) {
    if (toPick == 0) {
        ++ans;
        return;
    }
    int smallest = 0;
    while (picked[smallest]) ++smallest;
    picked[smallest] = true;
    for (int next = smallest + 1; next < n; ++next) {
        if (picked[next] || !friendship[smallest][next]) continue;
        picked[next] = true;
        pick(toPick - 1);
        picked[next] = false;
    }
    picked[smallest] = false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int C; cin >> C;
    while (C--) {
        cin >> n >> m;
        friendship = vector<vector<bool>>(n, vector<bool>(n));
        while (m--) {
            int a, b; cin >> a >> b;
            friendship[a][b] = true;
            friendship[b][a] = true;
        }
        picked = vector<bool>(n);
        ans = 0;
        pick(n / 2);
        cout << ans << "\n";
    }

    return 0;
}
