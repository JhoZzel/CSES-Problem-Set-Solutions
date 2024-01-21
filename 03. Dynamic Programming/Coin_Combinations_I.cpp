#include <bits/stdc++.h>
using namespace std;
 
const int W = 1e6 + 5;
const int MOD = 1e9 + 7;

int dp[W];

int main() {
    int n, x; 
    cin >> n >> x;
    vector<int> a(n);
    for (int &e : a) cin >> e;
    dp[0] = 1;
    for (int sum = 0; sum <= x; sum++) {
        for (int i = 0; i < n; i++) {
            if (sum - a[i] < 0) continue;
            dp[sum] = (dp[sum] + dp[sum - a[i]]) % MOD;
        }
    }
    cout << dp[x] << "\n";
    return 0;
}
