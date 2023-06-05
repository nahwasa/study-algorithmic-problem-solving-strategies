//
// Created by RYUNA on 2023/04/14.
//
#include <bits/stdc++.h>
using namespace std;

typedef complex<double> cd;
const double pi = acos(-1);

vector<cd> fft(const vector<cd>& a, bool inv = false) {
    int n = a.size();
    vector<cd> r(n);
    for (int k = 0; k < n; ++k) {
        int b = 0;
        for (int z = 1; z < n; z <<= 1) {
            b <<= 1;
            if (k & z) b |= 1;
        }
        r[b] = a[k];
    }
    for (int m = 2; m <= n; m <<= 1) {
        cd wm = exp(cd(0, 2 * pi / m * (inv ? -1 : 1)));
        for (int k = 0; k < n; k += m) {
            cd w = 1;
            for (int j = 0; j < m / 2; ++j) {
                cd u = r[k + j];
                cd t = w * r[k + j + m / 2];
                r[k + j] = u + t;
                r[k + j + m / 2] = u - t;
                w *= wm;
            }
        }
    }
    if (inv) for (int i = 0; i < n; ++i) r[i] /= n;
    return r;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int c; cin >> c;
    while (c--) {
        string A, B;
        cin >> A >> B;
        int n = A.size(), m = B.size();
        int MAX = 1;
        while (MAX < m) MAX <<= 1;
        vector<cd> SS(MAX), F(MAX), tr(MAX);
        for (int i = 0; i < n; ++i) SS[i] = A[i] == 'M' ? 1 : 0;
        for (int i = 0; i < m; ++i) F[i] = B[m - i - 1] == 'M' ? 1 : 0;
        auto ts = fft(SS), tf = fft(F);
        for (int i = 0; i < MAX; ++i) tr[i] = ts[i] * tf[i];
        auto r = fft(tr, true);
        int ans = 0;
        for (int i = n - 1; i < m; ++i) ans += lround(r[i].real()) == 0;
        cout << ans << '\n';
    }

    return 0;
}