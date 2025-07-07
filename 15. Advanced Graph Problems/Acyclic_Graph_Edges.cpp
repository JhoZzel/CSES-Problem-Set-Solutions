#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 2e5 + 5;

int n,m;
int color[N];
bool used[N];
vector<pair<int,int>> G[N];
vector<pair<int,int>> edges;

void dfs(int u) {
    color[u] = 1;
    for (auto [v, id] : G[u]) {
        if (used[id]) continue;
        used[id] = 1;
        if (color[v] == 2) {
            edges.emplace_back(u, v);
        } else if (color[v] == 1) {
            edges.emplace_back(v, u);
        } else {
            edges.emplace_back(u, v);
            dfs(v);
        }
    }
    color[u] = 2;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u,v;
        cin >> u >> v;
        u--; v--;
        G[u].emplace_back(v, i);
        G[v].emplace_back(u, i);
    }

    for (int i = 0; i < n; i++) {
        if (!color[i]) dfs(i);
    }
    assert((int)edges.size() == m);
    for (auto [u, v] : edges) cout << ++u << " " << ++v << "\n";

    return 0;
}
