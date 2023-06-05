#include <iostream>
#include <cstring>

using namespace std;

const int BOARD_SIZE = 5;
const int A_TO_Z = 'Z'-'A'+1;
char board[BOARD_SIZE][BOARD_SIZE] = {0};
bool chk[A_TO_Z] = {0};
bool v[BOARD_SIZE][BOARD_SIZE][10];

bool find(string str, int idx, int r, int c) {
    if (idx == str.length())
        return true;

    char next = str[idx];
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i==0 && j==0) continue;
            int nr = r+i;
            int nc = c+j;
            if (nr<0 || nr>=BOARD_SIZE || nc<0 || nc>=BOARD_SIZE || board[nr][nc] != next || v[nr][nc][idx])
                continue;

            v[nr][nc][idx] = true;
            if (find(str, idx+1, nr, nc))
                return true;
        }
    }

    return false;
}

bool isPossibleToFind(string str) {
    memset(v, false, sizeof(v));

    int len = str.length();
    for (int i = 0; i < len; i++) {
        if (!chk[str[i]-'A'])
            return false;
    }

    char first = str[0];


    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] != first || !find(str, 1, i, j)) continue;
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int c;
    cin >> c;
    while (c--) {

        for (int i = 0; i < BOARD_SIZE; i++) {
            string row;
            cin >> row;
            for (int j = 0; j < BOARD_SIZE; j++) {
                chk[row[j]-'A'] = true;
                board[i][j] = row[j];
            }
        }

        int n;
        cin >> n;
        while (n--) {
            string str;
            cin >> str;
            cout << str << " " << (isPossibleToFind(str) ? "YES" : "NO") << '\n';
        }

    }
}


