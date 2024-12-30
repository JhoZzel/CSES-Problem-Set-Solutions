#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 2e5 + 5;
const int K = 22;

int n,q;
int nodes;
int a[N];
int L[K * N];
int R[K * N];
ll T[K * N];

int new_leaf(int x) {
    int id = nodes++;
    L[id] = R[id] = -1;
    T[id] = x;
    return id;
}

int new_par(int l_id, int r_id) { 
    int id = nodes++;
    L[id] = l_id; 
    R[id] = r_id;
    T[id] = T[L[id]] + T[R[id]];
    return id;
}

int build(int tl = 1, int tr = n) { 
    if (tl == tr) return new_leaf(a[tl]);
    int tm = (tl + tr) / 2; 
    return new_par(build(tl, tm), build(tm + 1, tr));
}

int update(int id, int pos, int x, int tl = 1, int tr = n) { 
    if (tl == tr) return new_leaf(x);
    int tm = (tl + tr) / 2;
    if (pos <= tm) return new_par(update(L[id], pos, x, tl, tm), R[id]);
    else return new_par(L[id], update(R[id], pos, x, tm + 1, tr));
}

ll query(int id, int l, int r, int tl = 1, int tr = n) {
    if (l > r) return 0ll;
    if (tl == l and tr == r) return T[id];
    int tm = (tl + tr) / 2;
    ll valL = query(L[id], l, min(r, tm), tl, tm);
    ll valR = query(R[id], max(l, tm + 1), r, tm + 1, tr);
    return valL + valR;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> root = {-1};
    root.push_back(build());
    while(q--) {
        int op; cin >> op;
        if (op == 1) {
            int k,pos,x;
            cin >> k >> pos >> x;
            root[k] = update(root[k], pos, x);
        } else if (op == 2) {
            int k,l,r;
            cin >> k >> l >> r;
            cout << query(root[k], l, r) << '\n';
        } else {
            int k; cin >> k;
            root.push_back(root[k]);
        }
    }
    return 0;
}
