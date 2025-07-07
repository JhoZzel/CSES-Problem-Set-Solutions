#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int LOG = 20;

int n,m,q;
int timer;
int tin[N];
int tout[N];
int h[N];
int up[N][LOG];
int mx[N][LOG];
vector<pair<int,int>> G[N];

int sz[N];
int par[N];

int get(int a) {
    return (a == par[a]) ? a : par[a] = get(par[a]);
}
bool join(int a, int b){
    a = get(a);
    b = get(b);
    if (a == b) return 0;
    if (sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b];
    par[b] = a;
    return 1;
}

bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] and tout[u] >= tout[v];
}

void dfs(int u, int p, int mx_w = 0) {
    tin[u] = timer++;

    up[u][0] = p; 
    mx[u][0] = mx_w;

    for (int j = 1; j < LOG; j++) {
        int pu = up[u][j - 1];
        up[u][j] = up[pu][j - 1];
        mx[u][j] = max(mx[u][j - 1], mx[pu][j - 1]);
    }

    for (auto [v, w] : G[u]) {
        if (v == p) continue;
        h[v] = h[u] + 1; 
        dfs(v, u, w);
    }

    tout[u] = timer++;
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

int go_up(int u, int len) {
    int ans = 0;
    for (int j = LOG - 1; j >= 0; j--) {
        if ((len >> j) & 1) {
            ans = max(ans, mx[u][j]);
            u = up[u][j];
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    memset(up,-1,sizeof(up));
    
    for (int i = 0; i < N; i++) {
        par[i] = i;
        sz[i] = 1;
    }

    cin >> n >> m >> q;
    for (int i = 1; i <= m; i++) {
        int u,v;
        cin >> u >> v;
        u--; v--;
        if (join(u, v)) {
            G[u].emplace_back(v, i);
            G[v].emplace_back(u, i);
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (~up[i][0]) continue;
        dfs(i, i);
    }

    
    while(q--) {
        int u,v;
        cin >> u >> v;
        u--; v--;
        if (get(u) != get(v)) {
            cout << "-1\n";
            continue;
        } 
        int ans = 0;
        int w = lca(u, v);
        ans = max(ans, go_up(u, h[u] - h[w]));
        ans = max(ans, go_up(v, h[v] - h[w]));
        cout << ans << "\n";
    }

    return 0;
}
