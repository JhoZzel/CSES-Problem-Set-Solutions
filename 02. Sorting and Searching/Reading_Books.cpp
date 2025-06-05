#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int n; cin >> n;
    vector<int> a(n);
    for (int &e : a) cin >> e;
    
    int mx = *max_element(a.begin(), a.end());

    ll sa = 0;
    for (int x : a) sa += x;

    if (mx > sa - mx) {
        cout << 2 * mx << "\n";
    } else {
        cout << sa << "\n";
    }

    return 0;
}
