#include <bits/stdc++.h>
using namespace std;

string s;
int i;

string solve() {
    char head = s[i++];
    if (head == 'b') {
        return "b";
    }
    if (head == 'w') {
        return "w";
    }
    string a = solve();
    string b = solve();
    string c = solve();
    string d = solve();
    return "x" + c + d + a + b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int C; cin >> C;
    while (C--) {
        cin >> s;
        i = 0;
        cout << solve() << "\n";
    }

    return 0;
}
