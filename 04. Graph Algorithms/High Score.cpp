#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)
using namespace std;
typedef long long ll;

const int N = 2.5e3 + 5;
const ll INF = 1e18 + 5;

int n;
int m;
bool vis[N];
ll D[N];
vector<int> bad;
vector<int> G[N];
vector<tuple<int,int,int>> edges;

void DFS(int u) {
    vis[u] = true;
    for (int v : G[u]) {
        if (vis[v]) continue;
        DFS(v);
    }
}

void bellman_ford(int s0) {
    fill(D, D + n, INF);
    D[s0] = 0;
    for (int i = 0; i < n; i++) {
        for (auto [u,v,w] : edges) {
            if (D[u] == INF) continue;
            if (D[u] + w < D[v]) {
                D[v] = D[u] + w;
            }
        }
    }
    for (auto [u, v, w] : edges) {
        if (D[u] == INF) continue;
        if (D[u] + w < D[v]) {
            bad.push_back(v);
        }
    }
}

void solve() {
    bellman_ford(0);
    bool ok = true;
    for (int u : bad) {
        if (vis[u]) continue;
        DFS(u);
        if (vis[n - 1]) ok = false;
    }
    cout << ((ok and D[n - 1] < INF) ? -D[n - 1] : -1) << "\n";
}

int main() {
    fast_io;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        u--; v--;
        edges.emplace_back(u,v,-w);
        G[u].push_back(v);
    }
    solve();
    return 0;
}
