//
// Created by RYUNA on 2023/05/22.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int C; cin >> C;
    while (C--) {
        string str; cin >> str;
        stack<int> s;
        bool flag = true;
        for (char j : str) {
            switch (j) {
                case '(':
                    s.push(1);
                    break;
                case '{':
                    s.push(2);
                    break;
                case '[':
                    s.push(3);
                    break;
                case ')':
                    if (s.empty() || s.top() != 1) flag = false;
                    else s.pop();
                    break;
                case '}':
                    if (s.empty() || s.top() != 2) flag = false;
                    else s.pop();
                    break;
                case ']':
                    if (s.empty() || s.top() != 3) flag = false;
                    else s.pop();
                    break;
                default:
                    break;
            }
            if (!flag) break;
        }
        if (!s.empty()) flag = false;
        cout << (flag ? "YES" : "NO") << '\n';
    }

    return 0;
}