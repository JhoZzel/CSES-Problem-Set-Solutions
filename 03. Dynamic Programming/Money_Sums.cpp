#include <bits/stdc++.h>
using namespace std;
 
const int MOD = 1e9 + 7;
const int N = 1e2 + 5;
const int M = 1e5 + 5;
 
bool dp[N][M];
 
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &e: a) cin >> e;
    for (int pos = 0; pos < N; pos++) dp[pos][0] = true;
    for (int pos = n - 1; pos >= 0; pos--) {
        for (int sum = 0; sum < M; sum++) {
            dp[pos][sum] = dp[pos + 1][sum];
            if (sum - a[pos] >= 0) {
                dp[pos][sum] = dp[pos + 1][sum] or dp[pos + 1][sum - a[pos]];
            } 
        }
    }
    vector<int> ans;
    for (int sum = 1; sum < M; sum++) {
        if (dp[0][sum]) {
            ans.push_back(sum);
        }
    }
    cout << ans.size() << "\n";
    for (int e : ans) {
        cout << e << " ";
    }
    return 0;
}
