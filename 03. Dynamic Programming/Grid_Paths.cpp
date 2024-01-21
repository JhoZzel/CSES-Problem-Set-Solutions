#include <bits/stdc++.h>
using namespace std;
 
const int MOD = 1e9 + 7;
const int N = 1e3 + 5;

int dp[N][N];

int main() {
    int n; cin >> n;
    vector<string> a(n);
    for (string &e : a) cin >> e;
    if (a[0][0] == '*') {
        cout << "0\n";
        return 0;
    }
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i + j == 0 or a[i][j] == '*') continue;
            if (i == 0) dp[i][j] = dp[i][j - 1];
            else if (j == 0) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
        }
    }
    cout << dp[n - 1][n - 1] << "\n";
    return 0;
}
