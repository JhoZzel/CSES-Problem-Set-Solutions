#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n;
int par[N];
int dp[N][2];
vector<int> G[N];

void get_parents(int u, int p) {
    for (int v : G[u]) {
        if (v == p) continue;
        par[v] = u;
        get_parents(v, u);
    }
}

int DFS(int u, bool on) {
    if (~dp[u][on]) return dp[u][on];
    int all = 0;
    for (int v : G[u]) {
        if (v == par[u]) continue;
        all += DFS(v, 0);
    } 
    
    if (on) return dp[u][on] = all;
    
    dp[u][on] = all;
    for (int v : G[u]) {
        if (v == par[u]) continue;
        dp[u][on] = max(dp[u][on], all - DFS(v, 0) + 1 + DFS(v, 1));
    }
    return dp[u][on];
}

int main() {
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u,v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    par[0] = -1;
    get_parents(0,-1);
    cout << DFS(0, 0) << "\n";
    return 0;
}
