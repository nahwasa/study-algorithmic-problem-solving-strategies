//
// Created by RYUNA on 2023/04/16.
//
#include <bits/stdc++.h>
using namespace std;

int n, mod = 1000000007;
vector<int> tile, sym;

int tiling(int width) {
    if (width <= 1) return 1;
    int& ret = tile[width];
    if (ret != -1) return ret;
    return ret = (tiling(width - 1) + tiling(width - 2)) % mod;
}

int symmetric(int width) {
    if (width <= 1) return 1;
    int& ret = sym[width];
    if (ret != -1) return ret;
    return ret = (symmetric(width - 2) + symmetric(width - 4)) % mod;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int c; cin >> c;
    while (c--) {
        cin >> n;
        tile = vector<int>(n + 1, -1);
        sym = vector<int>(n + 1, -1);
        cout << (tiling(n) - symmetric(n) + mod) % mod << '\n';
    }

    return 0;
}