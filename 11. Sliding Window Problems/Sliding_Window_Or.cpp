#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 7;

int n,k;
int x,a,b,c;
int v[N];
int id[N];
int pre[N];
int suf[N];

int query(int l, int r) {
    int id_l = id[l], id_r = id[r];
    int off_l = l - id_l * k;
    int off_r = r - id_r * k;
    if (id_l == id_r) return pre[id_l * k + off_r];
    return suf[id_l * k + off_l] | pre[id_r * k + off_r];
}

int main() {
    cin >> n >> k;
    cin >> x >> a >> b >> c;

    for (int i = 0; i < n; ++i) {
        v[i] = x;
        x = (1ll * a * x + b) % c;
    }

    const int B = (n + k - 1) / k;

    for (int j = 0; j < B; j++) {
        int s = j * k;
        int t = min(s + k, n);

        int off = j * k;

        pre[off] = v[s];
        for (int i = s + 1; i < t; i++) {
            id[i] = j;
            pre[off + i - s] = pre[off + i - s - 1] | v[i];
        }

        suf[off + t - s - 1] = v[t - 1];
        for (int i = t - 2; i >= s; --i) {
            suf[off + i - s] = suf[off + i - s + 1] | v[i];
        }
        id[s] = j;
    }

    int ans = 0;
    for (int j = k - 1; j < n; ++j) {
        int i = j - k + 1;
        ans ^= query(i, j);
    }
    cout << ans << "\n";

    return 0;
}
