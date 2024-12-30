#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n,q;
int a[N];
int T[4 * N];

void build(int id = 1, int tl = 1, int tr = n) {
    if (tl == tr) T[id] = a[tl];
    else {
        int tm = (tl + tr) / 2;
        build(2 * id, tl, tm);
        build(2 * id + 1, tm + 1, tr);
        T[id] = max(T[2 * id], T[2 * id + 1]);
    }
}

void update(int pos, int x, int id = 1, int tl = 1, int tr = n) {
    if (tl == tr) T[id] += x;
    else {
        int tm = (tl + tr) / 2;
        if (pos <= tm) update(pos, x, 2 * id, tl, tm);
        else update(pos, x, 2 * id + 1, tm + 1, tr);
        T[id] = max(T[2 * id], T[2 * id + 1]);
    }
}

int query(int x, int id = 1, int tl = 1, int tr = n) {
    if (T[id] < x) return 0;
    if (tl == tr) return tl;
    int tm = (tl + tr) / 2;
    int j = query(x, 2 * id, tl, tm);
    if (j != 0) return j;
    return query(x, 2 * id + 1, tm + 1, tr);
}

int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build();
    while(q--) {
        int x; cin >> x;
        int j = query(x);
        if (j) update(j, -x);
        cout << j << ' ';
    }
    return 0;
}
