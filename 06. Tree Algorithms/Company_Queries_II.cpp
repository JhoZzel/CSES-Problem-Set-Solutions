#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int LOG = 18;

int n,q;
int timer;
int h[N];
int tin[N];
int tout[N];
int up[N][LOG];
vector<int> G[N];

void dfs(int u, int p = 0) {
    tin[u] = timer++;

    up[u][0] = p;
    for (int j = 1; j < LOG; j++) {
        up[u][j] = up[up[u][j - 1]][j - 1];
    }

    for (int v : G[u]) {
        if (v == p) continue;
        h[v] = h[u] + 1;
        dfs(v, u);
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

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    cin >> n >> q;
    for (int i = 1; i < n; i++) {
        int p; cin >> p;
        p--;
        G[p].push_back(i);
    }

    dfs(0);
 
    while(q--) {
        int u,v;
        cin >> u >> v;
        u--; v--;
        cout << lca(u, v) + 1 << "\n";
    }
       
    return 0;
}
