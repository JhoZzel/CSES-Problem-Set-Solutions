#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)
using namespace std;

const int N = 1e5 + 5;

int n;
int m;
int par[N];
int color[N];
vector<int> cycle;
vector<int> G[N];

void DFS(int u) {
    color[u] = 1;
    for (int v : G[u]) {
        if (!cycle.empty()) return;
        if (color[v] == 2 or v == par[u]) continue;
        if (color[v] == 1) {
            cycle.push_back(v);
            while(u != v) {
                cycle.push_back(u);
                u = par[u];
            }
            cycle.push_back(v);
            reverse(cycle.begin(), cycle.end());
            return;
        }
        else {
            par[v] = u;
            DFS(v);
        }
    }
    color[u] = 2;
}

void solve() {
    fill(par, par + n, -1);
    for (int i = 0; i < n; i++) {
        if (color[i]) continue;
        DFS(i);
    }
    if (cycle.empty()) cout << "IMPOSSIBLE\n";
    else {
        cout << cycle.size() << "\n";
        for (int u : cycle) cout << u + 1 << " ";
        cout << "\n";
    }
}

int main() {
    fast_io;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u,v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    solve();
    return 0;
}
