//
// Created by RYUNA on 2023/05/08.
//
#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<int> L, M, G;

bool valid(int d) {
    int cnt = 0;
    for (int i = 0; i < N; ++i) {
        if (L[i] - M[i] <= d) {
            int x = min(d, L[i]) - (L[i] - M[i]);
            cnt += x / G[i] + 1;
        }
    }
    return cnt >= K;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int C; cin >> C;
    while (C--) {
        cin >> N >> K;
        L = M = G = vector<int>(N);
        for (int i = 0; i < N; i++) {
            cin >> L[i] >> M[i] >> G[i];
        }
        int l = 1, r = 1e9;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (!valid(mid)) l = mid + 1;
            else r = mid - 1;
        }
        cout << fixed << setprecision(2) << r + 1 << '\n';
    }

    return 0;
}