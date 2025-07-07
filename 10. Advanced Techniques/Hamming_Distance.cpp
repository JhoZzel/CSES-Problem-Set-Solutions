#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (char c : s) {
            a[i] = 2 * a[i] + (c - '0');
        }
    }
    int ans = k;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ans = min(ans, __builtin_popcount(a[i] ^ a[j]));
        }
    }
    cout << ans << "\n";

	return 0;
}
