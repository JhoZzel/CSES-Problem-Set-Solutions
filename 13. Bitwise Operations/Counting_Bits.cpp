#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ll x; cin >> x;
    x++;
    ll ans = 0;
    for (int i = 0; i <= __lg(x); i++) {
        ll k = (1ll << i);
        ll d = x / k;
        ll r = x % k;
        ans += (d / 2) * k;
        ans += (d % 2 == 1) * r;
    }
    cout << ans << "\n";

    return 0;
}
