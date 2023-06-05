#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> A;

ll solve(int p, int r) {
    if (p == r) return 0;
    int q = (p + r) / 2;
    ll ret = solve(p, q) + solve(q + 1, r);
    vector<int> L(A.begin() + p, A.begin() + q + 1), R(A.begin() + q + 1, A.begin() + r + 1);
    sort(R.begin(), R.end());
    for (int i : L) {
        ret += lower_bound(R.begin(), R.end(), i) - R.begin();
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    A = vector<int>(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    cout << solve(0, N-1);

    return 0;
}
