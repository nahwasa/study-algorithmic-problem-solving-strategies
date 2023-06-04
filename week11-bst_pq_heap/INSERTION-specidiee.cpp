#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
            tree_order_statistics_node_update> indexed_set;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int C; cin >> C;
    while (C--) {
        int N; cin >> N;
        vector<int> S(N), A(N);
        for (int i = 0; i < N; ++i) cin >> S[i];
        indexed_set s;
        for (int i = 1; i <= N; ++i) s.insert(i);
        for (int i = N - 1; i >= 0; --i) {
            auto k = s.find_by_order(i - S[i]);
            A[i] = *k;
            s.erase(k);
        }
        for (int i = 0; i < N; ++i) cout << A[i] << ' ';
        cout << '\n';
    }

    return 0;
}