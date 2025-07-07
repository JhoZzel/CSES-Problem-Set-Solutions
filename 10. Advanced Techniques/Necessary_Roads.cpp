#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n;
int m; 
int nc;
int timer;
int C[N];
int tin[N];
int low[N];
int deg[N];
bool vis[N];
bool bridge[N];
vector<pair<int,int>> edges;
vector<pair<int,int>> G[N];

void dfs(int u, int par = -1) {
    vis[u] = true;
    low[u] = tin[u] = timer++;
    for (auto [w, e] : G[u]) {
        if (w == par) continue;
        if (vis[w]) low[u] = min(low[u], tin[w]);
        else {
            dfs(w,u);
            low[u] = min(low[u], low[w]);
            if (low[w] > tin[u]) {
                bridge[e] = true;
            }
        }
    }
}

void solve() {
    dfs(0);
    fill(vis, vis + n, false);
    // We color the nodes for the same component
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        queue<int> Q;
        Q.emplace(i);
        vis[i] = true;
        while(!Q.empty()) {
            int u = Q.front(); Q.pop();
            C[u] = nc;
            for (auto [w, e] : G[u]) {
                if (bridge[e]) continue;
                if (vis[w]) continue;
                Q.push(w);
                vis[w] = true;
            }
        }
        nc++;
    } 
    vector<int> ans;
    for (int i = 0; i < m; i++) {
        if (bridge[i]) ans.push_back(i);
    }
    cout << ans.size() << "\n";
    for (int i : ans) cout << edges[i].first + 1 << " " << edges[i].second + 1 << "\n";
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].emplace_back(v, i);
        G[v].emplace_back(u, i);
        edges.emplace_back(u, v);
    }
    solve();
    return 0;
}
