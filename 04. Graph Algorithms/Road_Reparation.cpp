#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n;
int m;
int par[N];
int sz[N];
vector<tuple<int,int,int>> edges;

void init() {
    iota(par, par + n, 0);
    fill(sz, sz + n, 1);
}
int get(int a) {
    return a == par[a] ? a : par[a] = get(par[a]);
}
bool join(int a, int b) {
    a = get(a); b = get(b);
    if (a == b) return 0;
    if (sz[a] < sz[b]) swap(a,b);
    par[b] = a;
    sz[a] += sz[b];
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        u--; v--;
        edges.emplace_back(w,u,v);
    }
    sort(edges.begin(), edges.end());
 
    init();

    long long ans = 0;
    for (auto [w, u, v] : edges) {
        if (join(u, v)) {
            ans += w;
        }
    }
    
    if (sz[get(0)] != n) cout << "IMPOSSIBLE\n";
    else cout << ans << '\n';
    
    return 0;
}
