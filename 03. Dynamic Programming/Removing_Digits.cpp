#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e6 + 5;
const int INF = 1e9 + 5;

int dp[N];

int main() {
    int n; cin >> n;
    for (int i = 1; i < 10; i++) dp[i] = 1;
    for (int num = 10; num <= n; num++) {
        dp[num] = INF;
        for (char c : to_string(num)) {
            dp[num] = min(dp[num], 1 + dp[num - (c - '0')]);
        }
    }
    cout << dp[n] << "\n";
    return 0;
}
