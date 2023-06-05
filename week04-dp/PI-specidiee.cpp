//
// Created by RYUNA on 2023/04/10.
//
#include <bits/stdc++.h>
using namespace std;

string s;
vector<int> dp;

int solve(int x) {
    if (x == s.size()) return 0;
    int& ret = dp[x];
    if (ret != -1) return ret;
    ret = 1e9;
    for (int k = 3; k < 6; ++k) {
        if (x + k > s.size()) break;
        vector<int> v;
        for (char c : s.substr(x, k)) v.push_back(c - '0');
        int pt = 10;
        bool progressive = true;
        for (int i = 2; i < v.size(); i++) if (v[i] - v[i - 1] != v[i - 1] - v[i - 2]) progressive = false;
        if (progressive) pt = 5;
        bool alternate = true;
        for (int i = 2; i < v.size(); i++) if (v[i] != v[i - 2]) alternate = false;
        if (alternate) pt = 4;
        bool oneup = true;
        for (int i = 1; i < v.size(); i++) if (v[i] != v[i - 1] + 1) oneup = false;
        if (oneup) pt = 2;
        bool onedown = true;
        for (int i = 1; i < v.size(); i++) if (v[i] != v[i - 1] - 1) onedown = false;
        if (onedown) pt = 2;
        bool same = true;
        for (int i = 1; i < v.size(); i++) if (v[i] != v[0]) same = false;
        if (same) pt = 1;
        ret = min(ret, solve(x + k) + pt);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int c; cin >> c;
    while (c--) {
        cin >> s;
        dp = vector<int>(s.size(), -1);
        cout << solve(0) << '\n';
    }

    return 0;
}