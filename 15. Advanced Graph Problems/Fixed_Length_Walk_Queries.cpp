#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n,m,q;
int dis[N][2];
vector<int> G[N];
vector<tuple<int,int,int>> Q[N];

void bfs(int s0) {
    queue<pair<int,int>> Q;
    Q.emplace(s0, 0);
    dis[s0][0] = 0;
    while(!Q.empty()) {
        auto [u, p] = Q.front(); Q.pop();
        for (int v : G[u]) {
            if (dis[v][p ^ 1] != -1) continue;
            dis[v][p ^ 1] = 1 + dis[u][p];
            Q.emplace(v, p ^ 1);
        }
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    cin >> n >> m >> q;
    for (int i = 0; i < m; i++) {
        int u,v;
        cin >> u >> v;
        u--; v--;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    for (int i = 0; i < q; i++) {
        int u,v,x;
        cin >> u >> v >> x;
        u--; v--;
        Q[u].emplace_back(v, x, i);
    }

    vector<bool> ans(q);
    for (int u = 0; u < n; u++) {
        memset(dis,-1,sizeof(dis));
        bfs(u);
        for (auto [v, x, idx] : Q[u]) {
            if (dis[v][x % 2] == -1) continue;
            ans[idx] = dis[v][x % 2] <= x;
        }
    }
    for (int i = 0; i < q; i++) cout << (ans[i] ? "YES" : "NO") << "\n";

    return 0;
}
