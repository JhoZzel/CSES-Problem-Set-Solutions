#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {    
    int n; cin >> n;
    vector<pair<int,int>> a;
    for (int i = 0; i < n; i++) {
        int x,y;
        cin >> x >> y;
        a.emplace_back(x, y);
    }
    sort(a.begin(), a.end());

    ll ans = 0, t = 0;
    for (auto [x, y] : a) {
        t += x;
        ans += y - t;
    }
    cout << ans << '\n';
  
    return 0;
}
