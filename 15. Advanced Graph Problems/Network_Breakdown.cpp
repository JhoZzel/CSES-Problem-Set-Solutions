#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1e5 + 5;

int n,m,k;
int sz[N];
int par[N];
set<pair<int,int>> S;
vector<pair<int,int>> G[N];

int get(int a) {
    return (a == par[a]) ? a : par[a] = get(par[a]);
}

bool join(int a, int b) {
    a = get(a); b = get(b);
    if (a == b) return 0;
    if (sz[a] < sz[b]) swap(a, b);
    par[b] = a;
    sz[a] += sz[b];
    return 1; 
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
 
    for (int i = 0; i < N; i++) {
        par[i] = i;
        sz[i] = 1;
    }

    cin >> n >> m >> k;

    vector<pair<int,int>> edges;
    for (int i = 0; i < m; i++) {
        int u,v;
        cin >> u >> v;
        u--; v--;
        if (u > v) swap(u, v);
        edges.emplace_back(u, v);
    }

    set<pair<int,int>> banned;
    vector<pair<int,int>> Q;
    for (int i = 0; i < k; i++) {
        int u,v;
        cin >> u >> v;
        u--; v--;
        if (u > v) swap(u, v);
        Q.emplace_back(u, v);
        banned.emplace(u, v);
    }

    int nc = n;
    for (auto [u, v] : edges) {
        if (!banned.count(pair{u, v})) {
            nc -= join(u, v);
        }
    }

    vector<int> ans;
    reverse(Q.begin(), Q.end());
    for (auto [u, v] : Q) {
        ans.push_back(nc);
        nc -= join(u, v);
    }
    reverse(ans.begin(), ans.end());
    for (int e : ans) cout << e << " ";

    return 0;
}
