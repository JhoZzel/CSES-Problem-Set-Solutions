#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)
using namespace std;

const int N = 1e5 + 5;

int n,m;
int id[N];
bool bad;
bool vis[N];
vector<int> G[N];

void DFS(int u) {
    if (bad) return;
    vis[u] = true;
    for (int v : G[u]) {
        if (vis[v]) {
            if (id[v] == id[u]) bad = true;
            continue;
        }
        id[v] = id[u] ^ 1;
        DFS(v);
    }
}

void solve() {
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        DFS(i);
    }
    if (bad) cout << "IMPOSSIBLE\n";
    else {
        for (int i = 0; i < n; i++) {
            cout << id[i] + 1 << " ";
        }
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
