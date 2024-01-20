#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+ 5;
const int MOD = 1e9 + 7;

int main() {
    int n; cin >> n;
    int dp[N] = {};
    dp[0] = 1;
    for (int k = 1; k <= n; k++) {
        for (int d = 1; d <= 6; d++) {
            if (k - d < 0) break;
            dp[k] = (dp[k] + dp[k - d]) % MOD;
        }
    }
    cout << dp[n] << "\n";
    return 0;
}
