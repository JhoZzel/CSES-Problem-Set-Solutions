#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const int N = 2e5 + 5;

ll pre[N];
 
int main() {
    int n,S;
    cin >> n >> S;
    for (int i = 1; i <= n; i++) {
        cin >> pre[i];
        pre[i] += pre[i - 1];
    }
    ll ans = 0;
    for (int i = 0; i <= n; i++) {
        ll target = pre[i] + S;
        int L = lower_bound(pre, pre + n + 1, target) - pre;
        if (L == n + 1) continue;
        int R = upper_bound(pre, pre + n + 1, target) - pre - 1;
        ans += R - L + 1;
    }
    cout << ans << '\n';
    return 0;
}
