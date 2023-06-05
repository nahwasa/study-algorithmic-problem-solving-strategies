//
// Created by RYUNA on 2023/05/07.
//
#include <bits/stdc++.h>
using namespace std;

typedef complex<double> point;

const double EPSILON = 1e-6;
int N;
vector<point> points;
vector<bool> visited;

void dfs(int u, double d) {
    visited[u] = true;
    for (int v = 0; v < N; v++) {
        if (!visited[v] && abs(points[u] - points[v]) <= d) {
            dfs(v, d);
        }
    }
}

bool valid(double d) {
    visited = vector<bool>(N);
    dfs(0, d);
    for (int i = 0; i < N; i++) {
        if (!visited[i]) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int C; cin >> C;
    while (C--) {
        cin >> N;
        points = vector<point>(N);
        for (int i = 0; i < N; i++) {
            double x, y; cin >> x >> y;
            points[i] = point(x, y);
        }
        double l = 0.01, r = 2000.0;
        while (fabs(l - r) > EPSILON) {
            double mid = (l + r) / 2.0;
            if (!valid(mid)) l = mid;
            else r = mid;
        }
        cout << fixed << setprecision(2) << r << '\n';
    }

    return 0;
}