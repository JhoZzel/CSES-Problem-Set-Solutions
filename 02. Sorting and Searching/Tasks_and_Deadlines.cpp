#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<pair<int,int>> a(n);
    for (auto &[x, y] : a) cin >> x >> y;
    sort(a.begin(), a.end());

    long long ans = 0, t = 0;
    for (auto [x, y] : a) {
        t += x;
        ans += y - t;
    }
    cout << ans << '\n';

    return 0;
}
