#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &e : a) cin >> e;
    
    auto p = [&](ll mx) -> bool {
        ll sa = 0;
        int div = 1;
        for (int i = 0; i < n; i++) {
            sa += a[i];
            if (sa > mx) div++, sa = a[i];
        }
        return div <= k;
    };
    
    ll lo = *max_element(a.begin(), a.end());
    ll hi = accumulate(a.begin(), a.end(), 0ll);
    
    while(lo < hi) {
        ll mid = (lo + hi) / 2;
        if (!p(mid)) lo = mid + 1;
        else hi = mid;
    }
    cout << lo << '\n';

    return 0;
}
