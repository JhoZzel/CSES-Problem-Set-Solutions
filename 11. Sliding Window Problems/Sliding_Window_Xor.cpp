#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int n,k;
    cin >> n >> k;

    int x,a,b,c;
    cin >> x >> a >> b >> c;

    vector<int> v;
    for (int i = 0; i < n; i++) {
        v.push_back(x);
        x = (1ll * a * x + b) % c;
    }
    
    int ans = 0;
    int cur = 0;
    for (int i = 0; i < k - 1; i++) cur ^= v[i];
    for (int i = k - 1; i < n; i++) {
        cur ^= v[i];
        ans ^= cur;
        cur ^= v[i - k + 1];
    }
    cout << ans << "\n";

    return 0;
}
