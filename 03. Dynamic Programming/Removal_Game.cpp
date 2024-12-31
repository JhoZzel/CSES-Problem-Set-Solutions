#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 5000 + 5;

int n;
int a[N];
ll pre[N];
ll dp[2][N][N];

ll query(int i, int j) {
    if (i > j) return 0;
    return pre[j] - pre[i - 1];
}

ll f(int p, int i, int j) {
    if (i > j) return 0;
    if (~dp[p][i][j]) return dp[p][i][j];
    ll ans = LLONG_MIN;
    ans = max(ans, a[i] + query(i + 1, j) - f(p ^ 1, i + 1, j));
    ans = max(ans, a[j] + query(i, j - 1) - f(p ^ 1, i, j - 1));
    return dp[p][i][j] = ans;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    memset(dp,-1,sizeof(dp));
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    cout << f(1, 1, n) << '\n';
    return 0;
}
