#include <bits/stdc++.h>
using namespace std;

const int N = 1000 + 5;

int FT[N][N];

void update(int i, int j, int x) {
    for (; i < N; i += i & -i) {
        for (int jj = j; jj < N; jj += jj & -jj) {
            FT[i][jj] += x;
        }
    }
}
int sum(int i, int j) {
    int sa = 0;
    for (; i; i -= i & -i) {
        for (int jj = j; jj; jj -= jj & -jj) {
            sa += FT[i][jj];
        }
    }
    return sa;
}
int query(int i1, int j1, int i2, int j2) {
    return sum(i2, j2) - sum(i2, j1 - 1) - sum(i1 - 1, j2) + sum(i1 - 1, j1 - 1);
}

int main() {
    int n,q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char c; cin >> c;
            if (c == '*') {
                update(i, j, 1);
            }
        }
    }
    while(q--) {
        int op; cin >> op;
        if (op == 1) {
            int i,j;
            cin >> i >> j;
            int at = query(i,j,i,j);
            update(i, j, at ? -1 : 1);
        }
        else {
            int i1,j1,i2,j2;
            cin >> i1 >> j1 >> i2 >> j2;
            cout << query(i1, j1, i2, j2) << '\n';
        }
    }
    return 0;
}
