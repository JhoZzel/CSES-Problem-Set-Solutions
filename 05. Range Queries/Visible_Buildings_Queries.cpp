#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int LOG = 18;

int n,q;
int a[N];
int go[N][LOG];

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<pair<int,int>> v = {{INT_MAX, n}};

    for (int i = n - 1; i >= 0; i--) {
        while(a[i] >= v.back().first) {
            v.pop_back();
        }
        go[i][0] = v.back().second;
        v.emplace_back(a[i], i);
    }
    go[n][0] = n;

    for (int j = 1; j < LOG; j++) {
        for (int i = 0; i <= n; i++) {
            go[i][j] = go[go[i][j - 1]][j - 1];
        }
    }

    while(q--) {
        int l,r;
        cin >> l >> r;
        l--; r--;
        int now = l;
        int ans = 1;
        for (int j = LOG - 1; j >= 0; j--) {
            if (go[now][j] <= r) {
                now = go[now][j];
                ans += 1 << j;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}
