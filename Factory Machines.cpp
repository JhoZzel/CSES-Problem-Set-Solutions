#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main() {
    int n,t;
    cin >> n >> t;
    vector<int> a(n);
    for (int &e : a) cin >> e;
    
    auto p = [&](ll time) -> bool {
        ll tt = 0;
        for (int i = 0; i < n; i++) {
            tt += time / a[i];
            if (tt >= t) return false;
        }
        return true;
    };

    ll lo = 0, hi = 1e18;
    while(lo < hi) {
        ll mid = (lo + hi) / 2;
        if (p(mid)) lo = mid + 1;
        else hi = mid;      
    }

    cout << lo << "\n";
    
    return 0;
}
 
