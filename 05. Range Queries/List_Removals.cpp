#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n;
int a[N];
int T[4 * N];

void build(int id = 1, int tl = 1, int tr = n) {
    if (tl == tr) T[id] = 1;
    else {
        int tm = (tl + tr) / 2;
        build(2 * id, tl, tm);
        build(2 * id + 1, tm + 1, tr);
        T[id] = T[2 * id] + T[2 * id + 1];
    }
}

void update(int pos, int x, int id = 1, int tl = 1, int tr = n) {
    if (tl == tr) T[id] = x;
    else {
        int tm = (tl + tr) / 2;
        if (pos <= tm) update(pos, x, 2 * id, tl, tm);
        else update(pos, x, 2 * id + 1, tm + 1, tr);
        T[id] = T[2 * id] + T[2 * id + 1];
    }
}

int query(int k, int id = 1, int tl = 1, int tr = n) {
    if (tl == tr) return tl;
    int tm = (tl + tr) / 2;
    if (k <= T[2 * id]) return query(k, 2 * id, tl, tm);
    else return query(k - T[2 * id], 2 * id + 1, tm + 1, tr);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build();
    for (int i = 1; i <= n; i++) {
        int k; cin >> k;
        int j = query(k);
        cout << a[j] << ' ';
        update(j, 0);
    }
    return 0;
}
