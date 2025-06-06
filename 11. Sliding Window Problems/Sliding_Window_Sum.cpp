#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int n,k;
    cin >> n >> k;

    int x,a,b,c;
    cin >> x >> a >> b >> c;

    vector<int> v;
    for (int i = 0; i < n; i++) {
        v.push_back(x);
        x = (1ll * a * x + b) % c;
    }

    ll ans = 0, sa = 0;
    for (int i = 0; i < k - 1; i++) sa += v[i];
    for (int i = k - 1; i < n; i++) {
        sa += v[i];
        ans ^= sa;
        sa -= v[i - k + 1];
    }
    cout << ans << "\n";

    return 0;
}
