#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int LOG = 18;

int n,q;
int h[N];
int up[N][LOG];
vector<int> G[N];

void dfs(int u, int p = 0) {

    up[u][0] = p;
    for (int j = 1; j < LOG; j++) {
        up[u][j] = up[up[u][j - 1]][j - 1];
    }

    for (int v : G[u]) {
        if (v == p) continue;
        h[v] = h[u] + 1;
        dfs(v, u);
    }
}

int go_up(int u, int d) {
    if (d > h[u]) return -1;
    for (int j = LOG - 1; j >= 0; j--) {
        if ((d >> j) & 1) {
            u = up[u][j];
        }
    }
    return u + 1;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    cin >> n >> q;
    for (int i = 1; i < n; i++) {
        int p; cin >> p;
        p--;
        G[p].push_back(i);
    }

    dfs(0);
 
    while(q--) {
        int u,k;
        cin >> u >> k;
        u--;
        cout << go_up(u, k) << "\n";
    }
       
    return 0;
}
