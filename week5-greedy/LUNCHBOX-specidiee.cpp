//
// Created by RYUNA on 2023/04/16.
//
#include <bits/stdc++.h>
using namespace std;

struct lunchbox {
    int m, e;
    bool operator>(const lunchbox& rhs) const {
        return e > rhs.e;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int c; cin >> c;
    while (c--) {
        int n, ans = 0, mEnd = 0; cin >> n;
        vector<lunchbox> ME(n);
        for (int i = 0; i < n; ++i) cin >> ME[i].m;
        for (int i = 0; i < n; ++i) cin >> ME[i].e;
        sort(ME.begin(), ME.end(), greater<>());
        for (int i = 0; i < n; ++i) {
            mEnd += ME[i].m;
            ans = max(ans, mEnd + ME[i].e);
        }
        cout << ans << '\n';
    }

    return 0;
}