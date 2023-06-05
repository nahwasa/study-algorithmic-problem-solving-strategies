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
        priority_queue<int, vector<int>, greater<>> pq;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            pq.push(x);
        }
        while (!pq.empty()) {
            int x = pq.top(); pq.pop();
            if (pq.empty()) break;
            int y = pq.top(); pq.pop();
            pq.push(x + y);
            ans += x + y;
        }
        cout << ans << '\n';
    }

    return 0;
}