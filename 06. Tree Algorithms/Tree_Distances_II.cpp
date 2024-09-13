#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

vector<int> G[N];

int n;
int child[N]; 
long long dp[N]; 
long long up[N]; 

void dfs(int u, int p = 0) {
    child[u] = 1;
    for (int v : G[u]) {
        if (v == p) continue;     
        dfs(v, u);
        child[u] += child[v]; 
        dp[u] += dp[v] + child[v];
    }
}

void dfs2(int u, int p = 0) {
    for (int v : G[u]) {
        if (v == p) continue;
        up[v] += up[u] + dp[u] - 2 * child[v] - dp[v] + n;  
        dfs2(v,u);
    }
}

int main() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u,v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v); 
        G[v].push_back(u);
    }
    dfs(0); dfs2(0);
    for (int i = 0; i < n; i++) {
        cout << dp[i] + up[i] << ' ';
    }
    return 0;
}
