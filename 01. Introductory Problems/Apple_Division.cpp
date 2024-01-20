#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int &e : a) cin >> e;
    ll total = accumulate(a.begin(), a.end(), 0ll);
    ll nim = 1e9 + 5;
    for(int mask = 0; mask < (1 << n); mask++) {
        ll sa = 0;
        for (int i = 0; i < n; i++) {
            if ((mask >> i) & 1) sa += a[i];
        }
        nim = min(nim, llabs(total - 2 * sa));
    }
    cout << nim << "\n";
    return 0;
}
