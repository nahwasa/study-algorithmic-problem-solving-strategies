#include <iostream>
using namespace std;

int total;
int bit[1000002] = {0,};

int getPrefixSum(int ith) {
    int answer = 0l;
    while (ith > 0) {
        answer += bit[ith];
        ith -= ith&-ith;
    }
    return answer;
}

int query(int val) {
    return total - getPrefixSum(val);
}

void update(int ith) {
    while (ith <= 1000002) {
        bit[ith]++;
        ith += ith&-ith;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int c; cin >> c;
    while (c--) {
        int n; cin >> n;
        int sum = 0;
        total = 0;
        fill_n(bit, 1000002, 0);

        while (n--) {
            int cur; cin >> cur;
            cur++;

            sum += query(cur);
            update(cur);
            total++;
        }

        cout << sum << '\n';
    }
}
