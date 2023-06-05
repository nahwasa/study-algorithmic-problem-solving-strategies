//
// Created by RYUNA on 2023/04/16.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int c; cin >> c;
    while (c--) {
        int n, ans = 0; cin >> n;
        vector<int> R(n);
        multiset<int> K;
        for (int i = 0; i < n; ++i) cin >> R[i];
        for (int i = 0; i < n; ++i) {
            int k; cin >> k;
            K.insert(k);
        }
        for (int i = 0; i < n; ++i) {
            auto it = K.lower_bound(R[i]);
            if (it == K.end()) {
                K.erase(K.begin());
            } else {
                K.erase(it);
                ++ans;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}