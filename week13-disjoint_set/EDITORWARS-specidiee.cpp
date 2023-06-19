#include <bits/stdc++.h>
using namespace std;

class BipartiteUnionFind {
private:
    vector<int> link, enemy, rank, setSize;
    int numSets;
public:
    BipartiteUnionFind(int N) {
        if (N <= 0) return;
        link.assign(N, 0); for (int i = 0; i < N; ++i) link[i] = i;
        enemy.assign(N, -1);
        rank.assign(N, 0);
        setSize.assign(N, 1);
        numSets = N;
    }
    int findSet(int i) {
        return (link[i] == i) ? i : (link[i] = findSet(link[i]));
    }
    bool isSameSet(int i, int j) {
        return findSet(i) == findSet(j);
    }
    int sizeOfSet(int i) {
        return setSize[findSet(i)];
    }
    int unionSet(int i, int j) {
        if (i == -1 || j == -1) return max(i, j);
        if (isSameSet(i, j)) return findSet(i);
        int x = findSet(i), y = findSet(j);
        if (rank[x] > rank[y]) swap(x, y);
        link[x] = y;
        if (rank[x] == rank[y]) ++rank[y];
        setSize[y] += setSize[x];
        --numSets;
        return y;
    }
    bool ack(int i, int j) {
        i = findSet(i), j = findSet(j);
        if (enemy[i] == j) return false;
        int a = unionSet(i, j), b = unionSet(enemy[i], enemy[j]);
        enemy[a] = b;
        if (b != -1) enemy[b] = a;
        return true;
    }
    bool dis(int i, int j) {
        i = findSet(i), j = findSet(j);
        if (i == j) return false;
        int a = unionSet(i, enemy[j]), b = unionSet(j, enemy[i]);
        enemy[a] = b, enemy[b] = a;
        return true;
    }
    int maxParty() {
        int ret = 0;
        for (int node = 0; node < link.size(); ++node) {
            if (link[node] != node) continue;
            int myEnemy = enemy[node];
            if (myEnemy > node) continue;
            int mySize = sizeOfSet(node);
            int enemySize = (myEnemy == -1 ? 0 : sizeOfSet(myEnemy));
            ret += max(mySize, enemySize);
        }
        return ret;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int C; cin >> C;
    while (C--) {
        int N, M; cin >> N >> M;
        BipartiteUnionFind buf(N);
        int contradiction = 0;
        for (int i = 0; i < M; i++) {
            string s; int a, b; cin >> s >> a >> b;
            if (s == "ACK") {
                bool ack = buf.ack(a, b);
                if (!ack && contradiction == 0) contradiction = i + 1;
            }
            else if (s == "DIS") {
                bool dis = buf.dis(a, b);
                if (!dis && contradiction == 0) contradiction = i + 1;
            }
        }
        if (contradiction > 0) cout << "CONTRADICTION AT " << contradiction << '\n';
        else cout << "MAX PARTY SIZE IS " << buf.maxParty() << '\n';
    }

    return 0;
}