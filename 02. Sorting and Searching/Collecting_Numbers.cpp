#include <bits/stdc++.h>
using namespace std;
 
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int n; cin >> n;
    vector<int> idx(n);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        idx[--x] = i;
    }
    int ans = 1;
    int last = -1;
    for (int i : idx) {
        if (i < last) ans++;
        last = i;
    }
    cout << ans << '\n';

    return 0;
}
