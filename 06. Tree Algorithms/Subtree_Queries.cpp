#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 2e5 + 5;

int n;
int q;
int a[N];

int timer;
int tin[N];
int tout[N];
vector<int> G[N];

ll FT[2 * N];

ll sum(int i) {
    ll sa = 0;
    for (++i; i > 0; i -= i & -i) sa += FT[i];
    return sa;
}
ll query(int i, int j) {
    return sum(j) - sum(i - 1);
}
void update(int i, ll x) { 
    x -= query(i, i);
    for (++i; i < 2 * N; i += i & -i) FT[i] += x;
}

void dfs(int u, int p = -1) {
    tin[u] = timer++;
    for (int v : G[u]) {
        if (v == p) continue;
        dfs(v, u);
    }
    tout[u] = timer++;
}

int main() {
    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) {
        int u,v;
        cin >> u >> v;
        u--; v--;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    // Euler Tour
    dfs(0);
    for (int i = 0; i < n; i++) {
        update(tin[i], a[i]);
        update(tout[i], a[i]);
    }
 
    while(q--) {
        int op; cin >> op;
        if (op == 1) {
            int u,x;
            cin >> u >> x;
            u--;
            update(tin[u], x);
            update(tout[u], x);
        } else {
            int u; 
            cin >> u;
            u--;
            cout << query(tin[u], tout[u]) / 2 << '\n';
        }
    }
    return 0;
}
