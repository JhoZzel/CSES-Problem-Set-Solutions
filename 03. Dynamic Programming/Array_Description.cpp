#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MOD = 1e9 + 7;
const int N = 1e5 + 5;
const int M = 1e2 + 5;

int n,m;
int a[N];
ll dp[N][M];

ll f(int i, int last) {
    if (last <= 0 or last > m) return 0;
    if (i == n) return 1;
    if (~dp[i][last]) return dp[i][last];
    ll &ans = dp[i][last] = 0;
    if (a[i] == 0) {
        ans += f(i + 1, last);
        ans += f(i + 1, last + 1);
        ans += f(i + 1, last - 1);
        ans %= MOD;
    } else {
        if (abs(a[i] - last) > 1) return 0;
        ans = f(i + 1, a[i]);
    }
    return ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    memset(dp,-1,sizeof(dp));
 
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];

    ll ans = 0;
    if (a[0] == 0) {
        for (int x = 1; x <= m; x++) {
            ans += f(1, x);
        }
        ans %= MOD;
    } else {
        ans = f(0, a[0]);
    }
    cout << ans << "\n";

    return 0;
}
