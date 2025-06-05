#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int n; cin >> n;
    ll sa = 0;
    vector<int> a;
    for (int i = 0; i < n; i++) {
        int x,y;
        cin >> x >> y;
        sa += y;
        a.push_back(x);
    }
    sort(a.rbegin(), a.rend());
    for (int i = 0; i < n; i++) {
        sa -= 1ll * (i + 1) * a[i];
    }
    cout << sa << "\n";
    return 0;
}
