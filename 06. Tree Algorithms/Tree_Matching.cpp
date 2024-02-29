#include <bits/stdc++.h>
using namespace std;
 
const int N = 2e5 + 5;
 
int n;
int dp[N][2];
vector<int> G[N];
 
int DFS(int u, int p, bool on) {
    if (~dp[u][on]) return dp[u][on];
    int all = 0;
    for (int v : G[u]) {
        if (v == p) continue;
        all += DFS(v, u, 0);
    } 
    
    if (on) return dp[u][on] = all;
    
    dp[u][on] = all;
    for (int v : G[u]) {
        if (v == p) continue;
        dp[u][on] = max(dp[u][on], all - DFS(v, u, 0) + 1 + DFS(v, u, 1));
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
    cout << DFS(0, -1, false) << "\n";
    return 0;
}
