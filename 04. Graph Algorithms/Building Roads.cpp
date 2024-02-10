#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)
using namespace std;

const int N = 1e5 + 5;

int n;
int m;
bool vis[N];
vector<int> G[N];

void DFS(int u) {
    vis[u] = true;
    for (int v: G[u]) {
        if (vis[v]) continue;
        DFS(v);
    }
}

void solve() {
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        ans.push_back(i + 1);
        DFS(i);
    }
    int sz = ans.size();
    cout << sz - 1 << "\n";
    for (int i = 0; i < sz - 1; i++) {
        cout << ans[i] << " " << ans[i + 1] << "\n";
    }
}

int main() {
    fast_io;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u,v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    solve();
    return 0;
}
