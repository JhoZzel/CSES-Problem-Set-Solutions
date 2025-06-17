#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 2e5 + 4;
const int LOG = 20;

int n,m;
int timer;
int h[N];
int tin[N];
int tout[N];
int up[N][LOG];
bool is_black[N];
int mx_edge[N][LOG];
vector<pair<int,int>> G[N], T[N];

struct DSU {
    vector<int> par,sz;
    DSU (int n) : par(n), sz(n, 1) {
        iota(par.begin(), par.end(), 0);
    }
    int get(int u) {
        if (u == par[u]) return u;
        return par[u] = get(par[u]);
    }
    bool join(int u, int v) {
        u = get(u);
        v = get(v);
        if (u == v) return 0;
        if (sz[u] < sz[v]) swap(u, v);
        sz[u] += sz[v];
        par[v] = u;
        return 1;
    }
};


void dfs(int u, int p = 0, int w = 0) {
    tin[u] = timer++;

    up[u][0] = p;
    mx_edge[u][0] = w;

    for (int j = 1; j < LOG; j++) {
        int pu = up[u][j - 1];
        up[u][j] = up[pu][j - 1];
        mx_edge[u][j] = max(mx_edge[u][j - 1], mx_edge[pu][j - 1]);
    }

    for (auto [v, w] : T[u]) {
        if (v == p) continue;
        h[v] = h[u] + 1;
        dfs(v, u, w);
    }

    tout[u] = timer++;
}

bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] and tout[u] >= tout[v];
}

int lca(int u, int v) {
    if (is_ancestor(u, v)) return u;
    if (is_ancestor(v, u)) return v;
    for (int j = LOG - 1; j >= 0; j--) {
        if (!is_ancestor(up[u][j], v)) {
            u = up[u][j];
        }
    }
    return up[u][0];
}

int go_up(int u, int dis) {
    int mx = 0;
    for (int j = LOG - 1; j >= 0; j--) {
        if ((dis >> j) & 1) {
            mx = max(mx, mx_edge[u][j]);
            u = up[u][j];
        }
    }
    return mx;
}

int query(int u, int v) {
    int w = lca(u, v);
    if (h[u] > h[v]) swap(u, v);
    int mx1 = go_up(u, h[u] - h[w]);
    int mx2 = go_up(v, h[v] - h[w]);
    return max(mx1, mx2);
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n >> m;
    vector<tuple<int,int,int,int>> edges;
    for (int i = 0; i < m; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        u--; v--;
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
        edges.emplace_back(w, u, v, i);
    }
    DSU dsu(n);
    sort(edges.begin(), edges.end());
    ll mst = 0;
    for (auto [w, u, v, id] : edges) {
        if (dsu.join(u, v)) {
            is_black[id] = true;
            mst += w;
            T[u].emplace_back(v, w);
            T[v].emplace_back(u, w);
        }
    }

    dfs(0);
    vector<ll> ans(m, -1);
    for (auto [w, u, v, id] : edges) {
        if (is_black[id]) ans[id] = mst;
        else {
            int mx = query(u, v);
            ans[id] = mst - mx + w;
        }
    }

    for (ll x : ans) cout << x << "\n";

    return 0;
}
