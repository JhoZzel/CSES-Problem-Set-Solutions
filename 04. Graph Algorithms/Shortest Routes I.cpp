#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)
using namespace std;
typedef long long ll;

const int N = 1e5 + 5;
const ll INF = 1e18 + 5;

int n;
int m;
ll D[N];
vector<pair<int,int>> G[N];

void dijkstra(int s0) {
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> Q;
    fill(D, D + n, INF);
    D[s0] = 0;
    Q.emplace(0,s0);
    while(!Q.empty()) {
        int u;
        ll d;
        tie(d,u) = Q.top(); Q.pop();
        if (d != D[u]) continue;
        for (auto [v, w] : G[u]) {
            if (D[u] + w < D[v]) {
                D[v] = D[u] + w;
                Q.emplace(D[v], v);
            }
        }
    }
}

int main() {
    fast_io;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        u--; v--;
        G[u].emplace_back(v,w);
        
    }
    dijkstra(0);
    for (int i = 0; i < n; i++) {
        cout << D[i] << " ";
    }
    return 0;
}
