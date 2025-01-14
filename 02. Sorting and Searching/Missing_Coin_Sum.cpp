#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int n; cin >> n;
    vector<int> a(n);
    for (int &e : a) cin >> e;

    sort(a.begin(), a.end());
    
    ll S = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] <= S + 1)
            S += a[i];
        else
            break;
    }
    cout << S + 1 << '\n';

    return 0;
}
