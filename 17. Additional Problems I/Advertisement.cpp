#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 2e5 + 5;
const int LOG = 18;

int n;
int a[N];
int ST[N][LOG];

void build() {
    for (int i = 0; i < n; i++) ST[i][0] = a[i];
    for (int p = 1, d = 1; 2 * d <= n; p++, d <<= 1) {
        for (int i = 0; i + 2 * d <= n; i++) {
            ST[i][p] = min(ST[i][p - 1], ST[i + d][p - 1]);
        }
    }
}

int query(int l, int r) {
    int p = __lg(r - l + 1);
    int d = 1 << p;
    return min(ST[l][p], ST[r - d + 1][p]);
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    build();
    
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int lo = i, hi = n - 1;
        while(lo < hi) { // 11100000
            int mid = (lo + hi + 1) / 2;
            if (query(i, mid) == a[i]) lo = mid;
            else hi = mid - 1;
        }
        int R = lo;

        lo = 0, hi = i; 
        while(lo < hi) { // 00001111
            int mid = (lo + hi) / 2;
            if (query(mid, i) == a[i]) hi = mid;
            else lo = mid + 1;
        }
        int L = lo;

        ans = max(ans, 1ll * a[i] * (R - L + 1));
    }

    cout << ans << "\n";
    
    return 0;
}
