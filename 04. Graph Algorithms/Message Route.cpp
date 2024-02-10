#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)
using namespace std;

const int N = 1e5 + 5;

int n;
int m;
int par[N];
int level[N];
vector<int> G[N];

void solve() {
    queue<int> Q;
    
    fill(level, level + n, -1);
    
    Q.push(0);
    level[0] = 0;
    par[0] = -1;
    
    while(!Q.empty()) {
        int u = Q.front(); Q.pop();
        for (int v : G[u]) {
            if (level[v] != -1) continue;
            level[v] = level[u] + 1;
            par[v] = u;
            Q.push(v);
        }
    }

    if (level[n - 1] == -1) cout << "IMPOSSIBLE\n";
    else {
        vector<int> path;
        int u = n - 1;
        while(u != -1) {
            path.push_back(u);
            u = par[u];
        }
        reverse(path.begin(), path.end());
        cout << path.size() << "\n";
        for (int u : path) cout << u + 1 << " ";
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
