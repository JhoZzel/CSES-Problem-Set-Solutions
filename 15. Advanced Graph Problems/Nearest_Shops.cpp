#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n,m,k;
int par[N][2];
int dis[N][2];
vector<int> G[N];

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    memset(dis,-1,sizeof(dis));
    
    queue<tuple<int,int,int>> Q;
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        int u; cin >> u;
        u--;
        dis[u][0] = 0;
        par[u][0] = u;
        Q.emplace(0, u, u);
    }

    for (int i = 0; i < m; i++) {
        int u,v;
        cin >> u >> v;
        u--; v--;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    while(!Q.empty()) {
        auto [D, u, sf] = Q.front(); Q.pop();
        for (int v : G[u]) {
            if (dis[v][0] == -1) {
                dis[v][0] = D + 1;
                par[v][0] = sf;
                Q.emplace(D + 1, v, sf);
            } else if (dis[v][1] == -1 and sf != par[v][0]) {
                dis[v][1] = D + 1;
                par[v][1] = sf;
                Q.emplace(D + 1, v, sf);
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (dis[i][0] == -1) cout << -1 << " ";
        else if (par[i][0] != i) cout << dis[i][0] << " ";
        else cout << dis[i][1] << " ";
    }

    return 0;
}
