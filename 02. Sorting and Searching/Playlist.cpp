#include <bits/stdc++.h>
using namespace std;
 
int main() {
    cin.tie(0) -> sync_with_stdio(0);
 
    int n; cin >> n;
    vector<int> a(n);
    for (int &e : a) cin >> e;

    int i = 0;
    int ans = 1;
    set<int> S = {a[0]};
    for (int j = 1; j < n; j++) {
        while (S.count(a[j])) {
            S.erase(a[i]);
            i++;
        }
        S.emplace(a[j]);
        ans = max(ans, j - i + 1);
    }
    cout << ans << '\n';

    return 0;
}
