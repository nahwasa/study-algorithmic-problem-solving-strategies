#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> maxtree, mintree;

void update(int node, int height) {
    node += N;
    maxtree[node] = mintree[node] = height;
    for (node /= 2; node >= 1; node /= 2) {
        maxtree[node] = max(maxtree[2 * node], maxtree[2 * node + 1]);
        mintree[node] = min(mintree[2 * node], mintree[2 * node + 1]);
    }
}

int query(int a, int b) {
    a += N; b += N;
    int maxret = 0, minret = 1e9;
    while (a <= b) {
        if (a % 2 == 1) {
            maxret = max(maxret, maxtree[a]);
            minret = min(minret, mintree[a]);
            a++;
        }
        if (b % 2 == 0) {
            maxret = max(maxret, maxtree[b]);
            minret = min(minret, mintree[b]);
            b--;
        }
        a /= 2; b /= 2;
    }
    return maxret - minret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int C; cin >> C;
    while (C--) {
        int Q; cin >> N >> Q;
        maxtree = mintree = vector<int>(2 * N);
        for (int i = 0; i < N; i++) {
            int h; cin >> h;
            update(i, h);
        }
        while (Q--) {
            int a, b; cin >> a >> b;
            cout << query(a, b) << '\n';
        }
    }

    return 0;
}