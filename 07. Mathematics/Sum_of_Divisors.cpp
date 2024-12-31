#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MOD = 1e9 + 7;
const int INV2 = 500000004;

int main() {
    ll n; cin >> n;
    int sq = sqrt(n);
    ll ans = 0;
    for (int i = 1; i < sq; i++) {
        ans += (n / i) % MOD * i % MOD;
        ans %= MOD;
    }
    for (int k = 1; k <= n / sq; k++) {
        ll b = n / k;
        b %= MOD;
        ll a = n / (k + 1);
        a %= MOD;
        ll add = (a + 1 + b) % MOD * (b - a + MOD) % MOD * INV2 % MOD * k % MOD;
        ans = (ans + add) % MOD;
    }
    cout << ans << '\n';
    return 0;
}
