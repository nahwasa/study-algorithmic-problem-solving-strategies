#include <bits/stdc++.h>
using namespace std;

typedef complex<int> point;

vector<point> X, Y;

int closest(vector<point>& Px, vector<point>& Py) {
    if (Px.size() <= 3) {
        int ret = 1e9;
        for (int i = 0; i < Px.size(); i++) {
            for (int j = i + 1; j < Px.size(); j++) {
                ret = min(ret, norm(Px[i] - Px[j]));
            }
        }
        return ret;
    }
    int mid = (int)Px.size() / 2;
    vector<point> Qx(Px.begin(), Px.begin() + mid), Rx(Px.begin() + mid, Px.end());
    vector<point> Qy, Ry;
    for (auto& p : Py) {
        if (p.real() < Qx.back().real()) {
            Qy.push_back(p);
        } else {
            Ry.push_back(p);
        }
    }
    int d = min(closest(Qx, Qy), closest(Rx, Ry));
    vector<point> Sy;
    for (auto& p : Py) {
        if (norm(point(p.real() - Qx.back().real(), 0)) < d) {
            Sy.push_back(p);
        }
    }
    for (int i = 0; i < Sy.size(); i++) {
        for (int j = i + 1; j < min((int)Sy.size(), i + 16); j++) {
            d = min(d, norm(Sy[i] - Sy[j]));
        }
    }
    return d;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    X = vector<point>(n);
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        X[i] = point(x, y);
    }
    Y = vector<point>(X);
    sort(X.begin(), X.end(), [](point a, point b) {
        return a.real() < b.real();
    });
    sort(Y.begin(), Y.end(), [](point a, point b) {
        return a.imag() < b.imag();
    });
    cout << closest(X, Y);

    return 0;
}
