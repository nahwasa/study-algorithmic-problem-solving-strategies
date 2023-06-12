#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N;
vector<int> tree;

void update(int k) {
    k += N;
    ++tree[k];
    for (k /= 2; k >= 1; k /= 2) {
        ++tree[k];
    }
}

ll count(int a, int b) {
    a += N; b += N;
    ll cnt = 0;
    while (a <= b) {
        if (a % 2) cnt += tree[a++];
        if (!(b % 2)) cnt += tree[b--];
        a /= 2; b /= 2;
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int C; cin >> C;
    while (C--) {
        cin >> N;
        tree = vector<int>(2 * N);
        vector<pair<int, int>> A(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i].first;
            A[i].second = i;
        }
        sort(A.begin(), A.end());
        ll cnt = 0;
        for (int i = 0; i < N; ++i) {
            cnt += count(A[i].second + 1, N - 1);
            update(A[i].second);
        }
        cout << cnt << '\n';
    }

    return 0;
}