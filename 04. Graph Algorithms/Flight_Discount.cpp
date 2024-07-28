#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,int> lli;
typedef priority_queue<lli, vector<lli>, greater<lli>> pq_min;

const int N = 1e5 + 5;
const ll INF = 1e15;

int n;
int m;
vector<pair<int,int>> G[2][N];

vector<ll> dijkstra(int id, int s0) {
    vector<ll> D(n, INF);
    pq_min pq;
    D[s0] = 0;
    pq.emplace(0,s0);
    while(!pq.empty()) {
        auto [d,u] = pq.top();
        pq.pop();
        if (d > D[u]) continue;
        for (auto [v, w] : G[id][u]) {
            if (D[u] + w < D[v]) {
                D[v] = D[u] + w;
                pq.emplace(D[v], v);
            }
        }
    }
    return D;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u,v,w; 
        cin >> u >> v >> w;
        u--; v--;
        G[0][u].emplace_back(v,w);
        G[1][v].emplace_back(u,w);
    }
    vector<ll> go = dijkstra(0, 0);
    vector<ll> back = dijkstra(1, n - 1);
    ll ans = INF;
    for (int u = 0; u < n; u++) {
        for (auto [v, w] : G[0][u]) {
            ans = min(ans, go[u] + w / 2 + back[v]);
        }
    }
    cout << ans << '\n';
    return 0;
}
