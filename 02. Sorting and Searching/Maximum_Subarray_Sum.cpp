#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int &e : a) cin >> e;
    ll ans = a[0];
    ll sa = 0;
    for (int i = 0; i < n; i++) {
        sa += a[i];
        if (sa > ans) ans = sa;
        if (sa < 0) sa = 0;
    }
    cout << ans << "\n";
    return 0;
}
