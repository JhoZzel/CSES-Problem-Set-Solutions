#include <bits/stdc++.h>
using namespace std;
 
const int INF = 1e9 + 5;
const int N = 5e2 + 5;
 
int dp[N][N];
bool vis[N][N];
 
int DP(int a, int b) {
    if (a == b) return 0;
    if (a < b) swap(a ,b);
    if (vis[a][b]) return dp[a][b];
    vis[a][b] = true;
    dp[a][b] = INF;
    for (int x = 1; x < a; x++) {
        dp[a][b] = min(dp[a][b], 1 + DP(a - x, b) + DP(x, b));
    }
    for (int x = 1; x < b; x++) {
        dp[a][b] = min(dp[a][b], 1 + DP(b - x, a) + DP(x, a));
    }
    return dp[a][b];
}
 
int main() {
    int n,m;
    cin >> n >> m;
    cout << DP(n, m) << "\n";
    return 0;
}
