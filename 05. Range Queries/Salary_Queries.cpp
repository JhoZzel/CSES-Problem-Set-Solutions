#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n,m,q;
int a[N];
int FT[3 * N];

void update(int i, int x) {
    for (++i; i < 3 * N; i += i & -i) {
        FT[i] += x;
    }
}
int sum(int i) {
    int sa = 0;
    for (++i; i > 0; i -= i & -i) sa += FT[i];
    return sa;
}
int query(int l, int r) {
    return sum(r) - sum(l - 1);
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<tuple<char,int,int>> Q;
    vector<int> t(a + 1, a + n + 1);
    for (int i = 0; i < q; i++) {
        char op; cin >> op;
        int x,y;
        cin >> x >> y;
        if (op == '?') t.push_back(x);
        t.push_back(y);
        Q.emplace_back(op, x, y);
    }

    // compress
    sort(t.begin(), t.end());
    t.erase(unique(t.begin(), t.end()), t.end());
    m = t.size();

    map<int,int> mp;
    for (int i = 0; i < m; i++) mp[t[i]] = i;
    for (int i = 1; i <= n; i++) a[i] = mp[a[i]];

    // build
    for (int i = 1; i <= n; i++) update(a[i], 1);
    // queries
    for (auto [op, x, y] : Q) {
        if (op == '!') {
            update(a[x], -1);
            a[x] = mp[y];
            update(a[x], 1);
        } else {
            cout << query(mp[x], mp[y]) << '\n';
        }
    }

    return 0;
}
