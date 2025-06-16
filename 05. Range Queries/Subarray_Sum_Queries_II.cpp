#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
const ll INF = 2e14 + 10;
const int N = 2e5 + 5;
 
struct node {
    ll sum, pre, suf, mx_sum;
 
    node() :
        sum(0), pre(0), suf(0), mx_sum(0) {}
 
    node(int x) : 
        sum(x), pre(x), suf(x), mx_sum(x) {}
 
    node operator + (const node R) const { // merge function
        node L = *this;
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
 
void build(int id = 1, int tl = 1, int tr = n) {
    if (tl == tr) {
        T[id] = node(a[tl]);
    }
    else {
        int tm = (tl + tr) / 2;
        build(2 * id, tl, tm);
        build(2 * id + 1, tm + 1, tr);
        T[id] = T[2 * id] + T[2 * id + 1];
    }
}
 
node query(int l, int r, int id = 1, int tl = 1, int tr = n) {
    if (l > r) return node();
    if (tl == l and tr == r) return T[id];
    int tm = (tl + tr) / 2;
    node valL = query(l, min(r, tm), 2 * id, tl, tm);
    node valR = query(max(tm + 1, l), r, 2 * id + 1, tm + 1, tr);
    return valL + valR;
}
 
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build();
    while(q--) {
        int l,r;
        cin >> l >> r;
        cout << query(l, r).mx_sum << "\n";
    }
    return 0;
}
