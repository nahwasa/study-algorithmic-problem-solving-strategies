#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> H;

ll solve(int l, int r) {
    if (l + 1 == r) return H[l];
    int m = (l + r) / 2;
    ll lmax = solve(l, m);
    ll rmax = solve(m, r);
    int middle_left = m - 1, middle_right = m;
    int middle_height = min(H[middle_left], H[middle_right]);
    ll mmax = 2LL * middle_height;
    while (middle_left > l || middle_right < r - 1) {
        if (middle_left > l && (middle_right == r - 1 || H[middle_left - 1] > H[middle_right + 1])) {
            middle_height = min(middle_height, H[--middle_left]);
        } else {
            middle_height = min(middle_height, H[++middle_right]);
        }
        mmax = max(mmax, (ll)middle_height * (middle_right - middle_left + 1));
    }
    return max(mmax, max(lmax, rmax));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int C; cin >> C;
    while (C--) {
        int N; cin >> N;
        H = vector<int>(N);
        for (int i = 0; i < N; ++i) cin >> H[i];
        cout << solve(0, N) << "\n";
    }

    return 0;
}
