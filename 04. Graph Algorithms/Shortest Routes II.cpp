#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)
using namespace std;
typedef long long ll;

const int N = 5e2 + 5;
const ll INF = 1e18 + 5;

int n;
int m;
int q;
ll D[N][N];

void floyd_warshall() {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (D[i][k] == INF or D[k][j] == INF) continue;
                if (D[i][k] + D[k][j] < D[i][j]) {
                    D[i][j] = D[i][k] + D[k][j];
                }
            }
        }
    }
}

void init() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            D[i][j] = (i == j) ? 0 : INF;
        }
    }
}

int main() {
    fast_io;
    cin >> n >> m >> q;
    init();
    for (int i = 0; i < m; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        u--; v--;
        D[v][u] = min(D[v][u], (ll) w);
        D[u][v] = min(D[u][v], (ll) w);
    }
    floyd_warshall();
    while(q--) {
        int u,v;
        cin >> u >> v;
        u--; v--;
        cout << ((D[u][v] < INF) ? D[u][v] : -1) << "\n";
    }
    return 0;
}
