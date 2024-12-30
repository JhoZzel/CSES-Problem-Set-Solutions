#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n,m,q;
int a[N];
int T[4 * N][2];

void build(int id = 1, int tl = 1, int tr = n) {
    if (tl == tr) {
        T[id][0] = a[tl] + tl;
        T[id][1] = a[tl] + n + 1 - tl;
    }
    else {
        int tm = (tl + tr) / 2;
        build(2 * id, tl, tm);
        build(2 * id + 1, tm + 1, tr);
        T[id][0] = min(T[2 * id][0], T[2 * id + 1][0]);
        T[id][1] = min(T[2 * id][1], T[2 * id + 1][1]);
    }
} 

void update(int pos, int x, int id = 1, int tl = 1, int tr = n) {
    if (tl == tr) {
        T[id][0] = x + tl;
        T[id][1] = x + n + 1 - tl;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm) update(pos, x, 2 * id, tl, tm);
        else update(pos, x, 2 * id + 1, tm + 1, tr);
        T[id][0] = min(T[2 * id][0], T[2 * id + 1][0]);
        T[id][1] = min(T[2 * id][1], T[2 * id + 1][1]);
    }
}

int query(int l, int r, int z, int id = 1, int tl = 1, int tr = n) {
    if (l > r) return INT_MAX;
    if (tl == l and tr == r) return T[id][z];
    int tm = (tl + tr) / 2;
    int valL = query(l, min(r, tm), z, 2 * id, tl, tm);
    int valR = query(max(tm + 1, l), r, z, 2 * id + 1, tm + 1, tr);
    return min(valL, valR);
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build();
    while(q--) {
        int op; cin >> op;
        if (op == 1) {
            int pos,x;
            cin >> pos >> x;
            update(pos, x);
        } else {
            int k; cin >> k;
            int right = query(k, n, 0) - k;
            int left = query(1, k, 1) - (n + 1 - k);
            cout << min(left, right) << '\n';
        }
    }
    return 0;
}
