//
// Created by RYUNA on 2023/05/15.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int C; cin >> C;
    while (C--) {
        int N, K; cin >> N >> K;
        list<int> josephus;
        for (int j = 1; j <= N; j++) josephus.push_back(j);
        auto death = josephus.begin();
        for (int j = 0; j < N - 2; j++) {
            death = josephus.erase(death);
            if (death == josephus.end()) death = josephus.begin();
            for (int i = 0; i < K - 1; i++) {
                ++death;
                if (death == josephus.end()) death = josephus.begin();
            }
        }
        cout << josephus.front() << " " << josephus.back() << endl;
    }

    return 0;
}