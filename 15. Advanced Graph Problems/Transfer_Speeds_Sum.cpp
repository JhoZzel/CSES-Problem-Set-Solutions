#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 2e5 + 5;

int sz[N];
int par[N];

int get(int a) {
    return (a == par[a]) ? a : par[a] = get(par[a]);
}

ll join(int a, int b, int w) {
    a = get(a); b = get(b);
    if (a == b) return 0;
    if (sz[a] < sz[b]) swap(a, b);
    ll add = 1ll * sz[a] * sz[b] * w;
    par[b] = a;
    sz[a] += sz[b];
    return add; 
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
 
    for (int i = 0; i < N; i++) {
        par[i] = i;
        sz[i] = 1;
    }

    int n; cin >> n;
    vector<tuple<int,int,int>> edges;
    for (int i = 1; i < n; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        u--; v--;
        edges.emplace_back(w, u, v);
    }
    sort(edges.rbegin(), edges.rend());

    ll ans = 0;
    for (auto [w, u, v] : edges) {
        ans += join(u, v, w);   
    }
    cout << ans << "\n";

    return 0;
}
