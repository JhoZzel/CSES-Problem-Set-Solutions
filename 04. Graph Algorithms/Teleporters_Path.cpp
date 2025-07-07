#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n,m;
int in[N];
int out[N];
bool vis[N];
vector<int> path;
vector<int> G[N];

void dfs(int u) { // Hierholzer
    while(!G[u].empty()) {
        int v = G[u].back();
        G[u].pop_back();
        dfs(v);
    }
    path.push_back(u);
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u,v;
        cin >> u >> v;
        u--; v--;

        G[u].emplace_back(v);
        out[u]++; 
        in[v]++;
    }

    // Path must start at node 0 and end at node n-1
    if (!(out[0] == in[0] + 1 and in[n - 1] == out[n - 1] + 1)) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    // The others nodes must has in = out
    for (int i = 1; i < n - 1; ++i) {
        if (in[i] != out[i]) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }

    dfs(0);
    reverse(path.begin(), path.end());

    if ((int)path.size() != m + 1 || (int)path.front() != 0 || (int)path.back() != n - 1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    for (int u : path) cout << u + 1 << " ";
    cout << "\n";

    return 0;
}
