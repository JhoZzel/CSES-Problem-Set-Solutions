#include <bits/stdc++.h>
using namespace std;
 
const int MOD = 1e9 + 7;
const int N = 5e2 + 5;
const int S = 6.3e4 + 5;

int dp[N][S];

int main() {
    int n; cin >> n;
    int ss = n * (n + 1) / 2;
    if (ss & 1) cout << 0 << "\n";
    else {
        for (int num = 1; num <= n; num++) dp[num][0] = 1;
        for (int num = n; num >= 1; num--) {
            for (int sum = 1; sum <= ss / 2; sum++) {
                dp[num][sum] = dp[num + 1][sum];
                if (sum - num >= 0) {
                    dp[num][sum] = (dp[num + 1][sum] + dp[num + 1][sum - num]) % MOD;
                }
            }
        }
        cout << dp[1][ss / 2] << "\n";
    }
    return 0;
}
