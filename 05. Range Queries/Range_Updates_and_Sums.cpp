#include <bits/stdc++.h>
using namespace std;

#define m first
#define b second

using ll = long long;

const int N = 2e5 + 5;

int n,q;
int a[N];
ll T[4 * N];
bool marked[4 * N];
pair<int,ll> lazy[4 * N];

void build(int id = 1, int tl = 1, int tr = n) {
    lazy[id] = {1, 0};
    if (tl == tr) T[id] = a[tl];
    else {
        int tm = (tl + tr) / 2;
        build(2 * id, tl, tm);
        build(2 * id + 1, tm + 1, tr);
        T[id] = T[2 * id] + T[2 * id + 1];
    }
}

void push(int id, int tl, int tr) {
    T[id] = T[id] * lazy[id].m + (tr - tl + 1) * lazy[id].b;
    if (tl != tr) {
        lazy[2 * id].m *= lazy[id].m;
        lazy[2 * id].b = lazy[2 * id].b * lazy[id].m + lazy[id].b;

        lazy[2 * id + 1].m *= lazy[id].m;
        lazy[2 * id + 1].b = lazy[2 * id + 1].b * lazy[id].m + lazy[id].b;

        marked[2 * id] = marked[2 * id + 1] = true;
    }
    lazy[id] = {1, 0};
    marked[id] = false;
}

void update(int l, int r, int z, int x, int id = 1, int tl = 1, int tr = n) {
    if (marked[id]) push(id, tl, tr);
    if (l > r) return;
    if (tl == l and tr == r) {
        lazy[id].m *= z;
        lazy[id].b = (z ? lazy[id].b : 0ll) + x;
        push(id, tl, tr);
    } else {
        int tm = (tl + tr) / 2;
        update(l, min(r, tm), z, x, 2 * id, tl, tm);
        update(max(tm + 1, l), r, z, x, 2 * id + 1, tm + 1, tr);
        T[id] = T[2 * id] + T[2 * id + 1];
    }
}

ll query(int l, int r, int id = 1, int tl = 1, int tr = n) {
    if (marked[id]) push(id, tl, tr);
    if (l > r) return 0ll;
    if (tl == l and tr == r) return T[id];
    int tm = (tl + tr) / 2;
    ll valL = query(l, min(tm, r), 2 * id, tl, tm);
    ll valR = query(max(tm + 1, l), r, 2 * id + 1, tm + 1, tr);
    return valL + valR;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build();
    while(q--) {
        int op; cin >> op;
        if (op != 3) {
            int l,r,x;
            cin >> l >> r >> x;
            update(l, r, (op == 1) ? 1 : 0, x);
        } else {
            int l,r;
            cin >> l >> r;
            cout << query(l, r) << '\n';
        }
    }
    return 0;
}
