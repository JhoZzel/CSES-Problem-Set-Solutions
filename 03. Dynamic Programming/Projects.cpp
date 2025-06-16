#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<tuple<int,int,int>> a(n);
    for (auto &[x, y, z] : a) cin >> x >> y >> z;
    sort(a.begin(), a.end());

    vector<ll> dp(n + 1);
    for (int i = n - 1; i >= 0; i--) {
        auto [l, r, val] = a[i];
        dp[i] = dp[i + 1];
        int j = lower_bound(a.begin(), a.end(), make_tuple(r + 1, -1, -1)) - a.begin();
        dp[i] = max(dp[i], dp[j] + val);
    }
    cout << dp[0] << "\n";

    return 0;
}
