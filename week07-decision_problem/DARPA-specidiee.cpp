//
// Created by RYUNA on 2023/05/05.
//
#include <bits/stdc++.h>
using namespace std;

const double EPSILON = 1e-6;

int N, M;
vector<double> L;

bool valid(double x) {
    int cnt = 1;
    double cur = L[0];
    for (int i = 1; i < M; ++i) {
        if (L[i] - cur >= x) {
            cur = L[i];
            ++cnt;
        }
    }
    return cnt >= N;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int C; cin >> C;
    while (C--) {
        cin >> N >> M;
        L = vector<double>(M);
        for (int i = 0; i < M; ++i) cin >> L[i];
        double l = 0.01, r = L.back() - L.front();
        while (fabs(l - r) > EPSILON) {
            double mid = (l + r) / 2.0;
            if (valid(mid)) l = mid;
            else r = mid;
        }
        cout << fixed << setprecision(2) << r << '\n';
    }

    return 0;
}