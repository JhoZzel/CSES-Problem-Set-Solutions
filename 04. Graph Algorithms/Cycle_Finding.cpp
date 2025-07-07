#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
const ll INF = 1e15 + 5;
const int N = 2500 + 5;
 
int n,m;
ll d[N];
bool vis[N];
int par[N];
deque<int> cycle;
vector<pair<int,int>> G[N];
vector<tuple<int,int,int>> edges;
 
void dfs(int u) {
    vis[u] = 1;
    for (auto [v, w] : G[u]) {
        if (!vis[v]) dfs(v);
        edges.emplace_back(u, v, w);
    }
}
 
bool solve(int id, int s0) {
    fill(d, d + n, INF);
    d[s0] = 0;
    if (id) {
        for (auto &[x, y, z] : edges) {
            swap(x, y);
        }
    }
 
    for (int i = 0; i < n; i++) {
        for (auto [u, v, w] : edges) {
            if (d[u] == INF) continue;
            if (d[u] + w < d[v]) {
                par[v] = u;
                d[v] = d[u] + w;
            }
        }
    }
 
    for (auto [u, v, w] : edges) {
        if (d[u] == INF) continue;
        if (d[u] + w < d[v]) {
            memset(vis, 0, sizeof(vis));
            int st = u;
            do {
                cycle.push_back(st);
                if (vis[st]) break;
                vis[st] = 1;
                st = par[st];
            } while(true);
            while(cycle.front() != st) cycle.pop_front();
            if (!id) reverse(cycle.begin(), cycle.end());
            return 1;
        }
    }
    return 0;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    fill(d, d + n, INF);
 
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        u--; v--;
        G[u].emplace_back(v, w);
    }
    
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        dfs(i);
        if (solve(0, i) or solve(1, i)) {
            cout << "YES\n";
            for (int e : cycle) cout << e + 1 << " ";
            return 0;
        } 
        edges.clear();
    }
 
    cout << "NO\n";
 
    return 0;
}
