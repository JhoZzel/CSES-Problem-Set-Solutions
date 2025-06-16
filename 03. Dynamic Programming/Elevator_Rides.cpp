#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll INF = 1e18;

int n;
int w_mx;
int w[20];
bool vis[1 << 20];
pair<int,ll> dp[1 << 20];

pair<int,ll> f(int mask) {
    if (mask == (1 << n) - 1) return {0, 0};
    if (vis[mask]) return dp[mask];
    vis[mask] = 1;
    pair<int,ll> ans = {n, INF};
    for (int i = 0; i < n; i++) {
        if ((mask >> i) & 1) continue;
        auto [cnt, acc] = f(mask | (1 << i));
        if (acc + w[i] <= w_mx) {
            ans = min(ans, {cnt, acc + w[i]});
        } else {
            ans = min(ans, {cnt + 1, w[i]});
        }
    }
    return dp[mask] = ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n >> w_mx;
    for (int i = 0; i < n; i++) cin >> w[i];
    auto [cnt, rest] = f(0);
    if (rest) cnt++;
    cout << cnt << "\n";

    return 0;
}
