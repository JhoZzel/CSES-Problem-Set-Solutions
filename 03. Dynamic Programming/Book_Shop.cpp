#include <bits/stdc++.h>
using namespace std;
 
const int MOD = 1e9 + 7;
const int N = 1e3 + 5;
const int M = 1e5 + 5;

int dp[N][M];

int main() {
    int n, x; 
    cin >> n >> x;
    vector<int> h(n), s(n);
    for (int &e : h) cin >> e;
    for (int &e : s) cin >> e;
    for (int val = 0; val < M; val++) dp[n][val] = 0;
    for (int pos = n - 1; pos >= 0; pos--) {
        for (int val = 0; val <= x; val++) {
            dp[pos][val] = dp[pos + 1][val];
            if (val - h[pos] >= 0) {
                dp[pos][val] = max(dp[pos + 1][val], dp[pos + 1][val - h[pos]] + s[pos]);
            }
        }
    }
    cout << dp[0][x] << "\n";
    return 0;
}
