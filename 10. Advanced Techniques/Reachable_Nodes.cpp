#include<bits/stdc++.h>
using namespace std;

const int N = 5e4 + 4;

int n,m;
int in[N];
int ans[N];
bool vis[N];
bitset<N> b[N];
vector<int> G[2][N];

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u,v;
        cin >> u >> v;
        u--; v--;
        G[0][u].emplace_back(v);
        G[1][v].emplace_back(u);
        in[v] += 1;
    }

    vector<int> order;
    queue<int> Q;
    for (int i = 0; i < n; i++) if (in[i] == 0) Q.push(i);
    while(!Q.empty()) {
        int u = Q.front(); Q.pop();
        order.push_back(u);
        for (int v : G[0][u]) {
            in[v]--;
            if (in[v] == 0) Q.push(v);
        }
    }
    reverse(order.begin(), order.end());

    for (int u : order) {
        b[u].set(u);
        ans[u] = b[u].count();
        for (int v : G[1][u]) {
            b[v] |= b[u];
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }

	return 0;
}
