#include<bits/stdc++.h>
using namespace std;

string s;
int idx;

string answer() {
    string result;

    if (s[idx] != 'x') {
        result.push_back(s[idx++]);
        return result;
    }

    idx++;
    string quadrant[5];
    for (int i = 1; i <= 4; i++)
        quadrant[i].append(answer());

    return result.append("x")
        .append(quadrant[3])
        .append(quadrant[4])
        .append(quadrant[1])
        .append(quadrant[2]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int c;
    cin >> c;
    while (c--) {
        cin >> s;
        idx = 0;
        cout << answer() << '\n';
    }
}
