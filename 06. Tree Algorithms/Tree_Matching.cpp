#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5 + 5;

int n;
int dp[N][2];
vector<int> G[N];

void dfs(int u, int p = -1) {
    int all = 0;
    for (int v : G[u]) {
        if (v == p) continue;
        dfs(v,u);
        all += dp[v][0];
    }
    dp[u][0] = dp[u][1] = all;
    for (int v : G[u]) {
        if (v == p) continue;
        dp[u][0] = max(dp[u][0], all - dp[v][0] + dp[v][1] + 1);
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
    dfs(0);
    cout << dp[0][0] << '\n';
    return 0;
}
