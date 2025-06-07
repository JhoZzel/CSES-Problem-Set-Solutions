#include <bits/stdc++.h>
using namespace std;

const int MAX = 124755;
const int MOD = 1e9 + 7;

int n,k;
int dp[2][MAX];
int pre[MAX];

int sum(int l, int r) {
    l = max(l, 0);
    int sa = pre[r];
    if (l) sa = (sa + MOD - pre[l - 1]) % MOD;
    return sa;
}

int main() {
    cin >> n >> k;
    dp[1][0] = 1;
    for (int i = 2; i <= n; i++) {
        int id = i & 1;
        pre[0] = dp[id ^ 1][0];
        for (int j = 1; j <= k; j++) pre[j] = (pre[j - 1] + dp[id ^ 1][j]) % MOD;
        for (int j = 0; j <= k; j++) {
            dp[id][j] = sum(j - i + 1, j);
        }
    }
    cout << dp[n & 1][k] << "\n";
    return 0;
}
