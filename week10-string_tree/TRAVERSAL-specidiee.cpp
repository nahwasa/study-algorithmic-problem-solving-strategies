#include <bits/stdc++.h>
using namespace std;

vector<int> preorder, inorder;

void postorder(int pre_start, int pre_end, int in_start, int in_end) {
    if (pre_start > pre_end || in_start > in_end) return;
    int root = preorder[pre_start];
    int root_idx = in_start;
    while (inorder[root_idx] != root) root_idx++;
    int left = root_idx - in_start;
    postorder(pre_start + 1, pre_start + left, in_start, root_idx - 1);
    postorder(pre_start + left + 1, pre_end, root_idx + 1, in_end);
    cout << root << ' ';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int C; cin >> C;
    while (C--) {
        int N; cin >> N;
        preorder = inorder = vector<int>(N);
        for (int i = 0; i < N; i++) cin >> preorder[i];
        for (int i = 0; i < N; i++) cin >> inorder[i];
        postorder(0, N - 1, 0, N - 1);
        cout << '\n';
    }

    return 0;
}