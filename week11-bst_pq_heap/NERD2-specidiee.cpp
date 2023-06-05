#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int C; cin >> C;
    while (C--) {
        int N; cin >> N;
        map<int, int> m;
        long long ans = 0;
        for (int i = 0; i < N; ++i) {
            int p, q; cin >> p >> q;
            auto it = m.lower_bound(p);
            if (it == m.end() || it->second < q) {
                if (it != m.begin()) {
                    for (--it; ; --it) {
                        if (it->second > q) break;
                        if (it == m.begin()) {
                            m.erase(it);
                            break;
                        }
                        else it = m.erase(it);
                    }
                }
                m[p] = q;
            }
            ans += m.size();
        }
        cout << ans << '\n';
    }

    return 0;
}