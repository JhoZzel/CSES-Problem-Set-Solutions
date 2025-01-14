#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int n; cin >> n;
    vector<int> a(n + 1);
    vector<ll> pre(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    ll total = accumulate(a.begin(), a.end(), 0ll);
    ll sa = 0;
    ll ans = LLONG_MAX;
    for (int i = 1; i <= n; i++) {
        int L = i - 1;
        int R = n - i;
        ans = min(ans, total + 1ll * a[i] * (L - R - 1) - 2 * sa);
        sa += a[i];
    }
    cout << ans << '\n';

    return 0;
}
