#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int C; cin >> C;
    while (C--) {
        int N, a, b, m, ans = 0; cin >> N >> a >> b;
        vector<ll> A(N);
        A[0] = 1983;
        for (int i = 1; i < N; ++i) {
            A[i] = (A[i - 1] * a + b) % 20090711;
        }
        priority_queue<int> small, large;
        for (int i = 0; i < N; ++i) {
            int I = A[i];
            if (!i) m = I;
            else if (i % 2) {
                if (I > m) large.push(-I);
                else {
                    large.push(-m);
                    small.push(I);
                    m = small.top();
                    small.pop();
                }
            } else {
                if (I > m) {
                    small.push(m);
                    large.push(-I);
                    m = -large.top();
                    large.pop();
                } else small.push(I);
            }
            ans = (ans + m) % 20090711;
        }
        cout << ans << '\n';
    }

    return 0;
}