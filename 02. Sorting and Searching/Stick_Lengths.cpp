#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int n; cin >> n;
    vector<int> a(n);
    for (int &e : a) cin >> e;
    sort(a.begin(), a.end());
 
    ll sa = 0;
    ll total = accumulate(a.begin(), a.end(), 0ll);
    ll ans = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        int L = i;
        int R = n - i - 1;
        ans = min(ans, total + 1ll * a[i] * (L - R - 1) - 2 * sa);
        sa += a[i];
    }
    cout << ans << '\n';
 
    return 0;
}
