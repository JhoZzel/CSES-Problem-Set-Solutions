#include <bits/stdc++.h>
using namespace std;
 
const int INF = 1e9 + 5;
const int N = 1e2+ 5;
const int V = 1e6 + 5;
 
int main() {
    int n, x;
    cin >> n >> x;
    int v[N];
    for (int i = 0; i < n; i++) cin >> v[i];
    int dp[N][V] = {};
    for (int C = 0; C < V; C++) dp[n][C] = INF;
    for (int i = 0; i < N; i++) dp[i][0] = 0;
    for (int pos = n - 1; pos >= 0; pos--) {
        for (int C = 0; C <= x; C++) {
            dp[pos][C] = dp[pos + 1][C];
            if (C - v[pos] >= 0) {
                dp[pos][C] = min(dp[pos + 1][C], 1 + dp[pos][C - v[pos]]);
            }
        }
    }
    cout << ((dp[0][x] < INF) ? dp[0][x] : -1) << "\n";
    return 0;
}
