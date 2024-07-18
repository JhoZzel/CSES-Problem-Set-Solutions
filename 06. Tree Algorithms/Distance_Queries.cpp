#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int LOG = 20;

int timer;
int tin[N];
int tout[N];
int dis[N];
int up[N][LOG];
vector<int> G[N];

void DFS(int v, int p = 0) {
    tin[v] = timer++;
    up[v][0] = p;
    for (int i = 1; i < LOG; i++) {
        up[v][i] = up[up[v][i - 1]][i - 1];
    }
    dis[v] = (v == p) ? 0 : 1 + dis[p];
    for (int to : G[v]) { 
        if (to == p) continue;
        DFS(to, v);
    }
    tout[v] = timer++;
}

bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] and tout[u] >= tout[v];
}

int lca(int u, int v) {
    if (is_ancestor(u, v)) return u;
    if (is_ancestor(v, u)) return v;
    for (int i = LOG - 1; i >= 0; i--) {
        if (!is_ancestor(up[u][i], v)) {
            u = up[u][i];
        }
    }
    return up[u][0];
}

int len(int u, int v) {
    return dis[u] + dis[v] - 2 * dis[lca(u,v)];
}

int main(){
    int n,q; 
    cin >> n >> q;
    for (int i = 1; i < n; i++) {
        int u,v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    DFS(0);
    while(q--) {
        int u,v;
        cin >> u >> v;
        u--; v--;
        cout << len(u, v) << '\n';
    }
    return 0;
}
