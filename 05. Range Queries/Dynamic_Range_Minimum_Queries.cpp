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
        T[id] = min(T[2 * id], T[2 * id + 1]);
    }
}

void update(int pos, int x, int id = 1, int tl = 1, int tr = n) {
    if (tl == tr) T[id] = x;
    else {
        int tm = (tl + tr) / 2;
        if (pos <= tm) update(pos, x, 2 * id, tl, tm);
        else update(pos, x, 2 * id + 1, tm + 1, tr);
        T[id] = min(T[2 * id], T[2 * id + 1]);
    }
}

int query(int l, int r, int id = 1, int tl = 1, int tr = n) {
    if (l > r) return INT_MAX;
    if (tl == l and tr == r) return T[id];
    int tm = (tl + tr) / 2;
    int valL = query(l, min(r, tm), 2 * id, tl, tm);
    int valR = query(max(tm + 1, l), r , 2 * id + 1, tm + 1, tr);
    return min(valL, valR);
}

int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build();
    while(q--) {
        int op; cin >> op;
        if (op == 1) {
            int pos, x;
            cin >> pos >> x;
            update(pos, x);
        } else {
            int l,r;
            cin >> l >> r;
            cout << query(l, r) << '\n';
        }
    }
    return 0;
}
