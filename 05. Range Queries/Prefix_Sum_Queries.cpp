#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 2e5 + 5;

int n,m,q;
int a[N];
ll pre[N];
ll lazy[4 * N];
ll T[4 * N];

void push(int id, int tl, int tr) {
    T[id] += lazy[id];
    if (tl != tr) {
        lazy[2 * id] += lazy[id];
        lazy[2 * id + 1] += lazy[id];
    }
    lazy[id] = 0;
}

void build(int id = 1, int tl = 0, int tr = n) {
    if (tl == tr) T[id] = pre[tl];
    else {
        int tm = (tl + tr) / 2;
        build(2 * id, tl, tm);
        build(2 * id + 1, tm + 1, tr);
        T[id] = max(T[2 * id], T[2 * id + 1]);
    }
} 

void update(int l, int r, int x, int id = 1, int tl = 0, int tr = n) {
    if (lazy[id]) push(id, tl, tr);
    if (l > r) return;
    if (tl == l and tr == r) {
        lazy[id] += x;
        push(id, tl, tr);
    } else {
        int tm = (tl + tr) / 2;
        update(l, min(tm, r), x, 2 * id, tl, tm);
        update(max(l, tm + 1), r, x, 2 * id + 1, tm + 1, tr);
        T[id] = max(T[2 * id], T[2 * id + 1]);
    }
}

ll query(int l ,int r, int id = 1, int tl = 0, int tr = n) {
    if (lazy[id]) push(id, tl, tr);
    if (l > r) return LLONG_MIN;
    if (tl == l and tr == r) return T[id];
    int tm = (tl + tr) / 2;
    ll valL = query(l, min(r, tm), 2 * id, tl, tm);
    ll valR = query(max(tm + 1, l), r, 2 * id + 1, tm + 1, tr);
    return max(valL, valR);
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    build();
    while(q--) {
        int op; cin >> op;
        if (op == 1) {
            int pos,x;
            cin >> pos >> x;
            int d = x - a[pos];
            update(pos, n, d);
            a[pos] = x;
        } else {
            int l,r;
            cin >> l >> r;
            ll ans = query(l, r) - query(l - 1, l - 1);
            if (ans < 0) ans = 0;
            cout << ans << '\n';
        }
    }
    return 0;
}
