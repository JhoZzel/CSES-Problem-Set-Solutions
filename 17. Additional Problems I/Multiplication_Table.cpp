#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll get(ll n, ll val) {
    ll cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (i > val) break;
        cnt += min(n, val / i);
    }
    return cnt;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    ll n; cin >> n;
    ll lo = 1, hi = n * n;
    while(lo < hi) { 
        ll mid = (lo + hi) / 2;
        if (get(n, mid) > n * n / 2) hi = mid;
        else lo = mid + 1;
    }
    cout << lo << "\n";

    return 0;
}
