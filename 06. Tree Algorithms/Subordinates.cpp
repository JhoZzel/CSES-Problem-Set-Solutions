#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n;
int dp[N];
vector<int> G[N];

int DFS(int u) {
    dp[u] = 0;
    for (int v : G[u]) {
        dp[u] += 1 + DFS(v);
    }
    return dp[u];
}

int main() {
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int x; cin >> x;
        G[x].push_back(i);
    }
    DFS(1);
    for (int i = 1; i <= n; i++) {
        cout << dp[i] << " ";
    }
    return 0;
}
