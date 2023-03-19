#include <bits/stdc++.h>
using namespace std;

int ans;
vector<int> clocks(16), clicks(10);
vector<vector<int>> switches = {
    {0, 1, 2},
    {3, 7, 9, 11},
    {4, 10, 14, 15},
    {0, 4, 5, 6, 7},
    {6, 7, 8, 10, 12},
    {0, 2, 14, 15},
    {3, 14, 15},
    {4, 5, 7, 14, 15},
    {1, 2, 3, 4, 5},
    {3, 4, 5, 9, 13}
};

void clickSwitch(int nextSwitch) {
    if (nextSwitch == 10) {
        bool perfect = true;
        for (int i : clocks) if (i != 0) perfect = false;
        if (perfect) {
            int clickSum = 0;
            for (int i : clicks) clickSum += i;
            ans = min(ans, clickSum);
        }
        return;
    }
    for (int i = 0; i < 4; ++i) {
        clicks[nextSwitch] = i;
        clickSwitch(nextSwitch + 1);
        for (int j : switches[nextSwitch]) clocks[j] = (clocks[j] + 1) % 4;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int C; cin >> C;
    while (C--) {
        for (int i = 0; i < 16; ++i) {
            cin >> clocks[i];
            clocks[i] = (clocks[i] / 3) % 4;
        }
        ans = 31;
        clickSwitch(0);
        cout << (ans == 31 ? -1 : ans) << "\n";
    }

    return 0;
}
