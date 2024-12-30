#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll INF = 2e14 + 10;
const int N = 2e5 + 5;

struct node {
    ll sum, pre, suf, mx_sum;

    node() :
        sum(0), pre(-INF), suf(-INF), mx_sum(-INF) {}

    node(int x) : 
        sum(x), pre(x), suf(x), mx_sum(x) {}

    friend node f(node &L, node &R) { // merge function
        node ans;
        ans.sum = L.sum + R.sum;
        ans.pre = max(L.pre, L.sum + R.pre);
        ans.suf = max(R.suf, R.sum + L.suf);
        ans.mx_sum = max({L.mx_sum, R.mx_sum, L.suf + R.pre});
        return ans;
    }
};

int n,q;
int a[N];
node T[4 * N];

// id => Node's idx in the tree 1-indexed
// [tl, tr] => Range of the node || root: [1, n]

void build(int id = 1, int tl = 1, int tr = n) {
    if (tl == tr) {
        T[id] = node(a[tl]);
    }
    else {
        int tm = (tl + tr) / 2;
        build(2 * id, tl, tm);
        build(2 * id + 1, tm + 1, tr);
        T[id] = f(T[2 * id], T[2 * id + 1]);
    }
}

void update(int pos, int x, int id = 1, int tl = 1, int tr = n) {
    if (tl == tr) T[id] = node(x);
    else {
        int tm = (tl + tr) / 2;
        if (pos > tm) update(pos, x, 2 * id + 1, tm + 1, tr);
        else update(pos, x, 2 * id, tl, tm);
        T[id] = f(T[2 * id], T[2 * id + 1]);
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build();
    while(q--) {
        int pos,x;
        cin >> pos >> x;
        update(pos, x);
        cout << max(0ll, T[1].mx_sum) << '\n';
    }
    return 0;
}
