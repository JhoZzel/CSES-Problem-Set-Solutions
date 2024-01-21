#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e2 + 5;
const int W = 1e6 + 5;
const int MOD = 1e9 + 7;

int dp[N][W];

int main() {
    int n, x; 
    cin >> n >> x;
    vector<int> a(n);
    for (int &e : a) cin >> e;
    for (int i = 0; i < N; i++) dp[i][0] = 1;
    for (int pos = n - 1; pos >= 0; pos--) {
        for (int sum = 0; sum <= x; sum++) {
            dp[pos][sum] = dp[pos + 1][sum];
            if (sum - a[pos] >= 0) {
                dp[pos][sum] = (dp[pos][sum] + dp[pos][sum - a[pos]]) % MOD;
            }
        }
    }
    cout << dp[0][x] << "\n";
    return 0;
}
