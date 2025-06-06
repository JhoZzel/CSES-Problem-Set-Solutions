#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()

using ll = long long;

const int N = 2e5 + 5;

int n,m,k;
int a[N];
ll sum[4 * N];
int cnt[4 * N];
vector<int> t;
 
void update(int pos, int x, int id = 1, int tl = 0, int tr = m - 1) {
    if (tl == tr) {
        cnt[id] += x;
        sum[id] = 1ll * t[tl] * cnt[id];
    }
    else {
        int tm = (tl + tr) / 2;
        if (pos <= tm) update(pos, x, 2 * id, tl, tm);
        else update(pos, x, 2 * id + 1, tm + 1, tr);

        cnt[id] = cnt[2 * id] + cnt[2 * id + 1];
        sum[id] = sum[2 * id] + sum[2 * id + 1];
    }
}
 
pair<ll, int> get_kth(int k, int id = 1, int tl = 0, int tr = m - 1) {
    if (tl == tr) return {1ll * t[tl] * k, tl};
    int tm = (tl + tr) / 2;
    if (k <= cnt[2 * id]) return get_kth(k, 2 * id, tl, tm);
    auto [sa, pos] = get_kth(k - cnt[2 * id], 2 * id + 1, tm + 1, tr);
    sa += sum[2 * id];
    return {sa, pos};
}
 
int main() {
    cin.tie(0) -> sync_with_stdio(0);
 
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        t.push_back(a[i]);
    }

    sort(all(t));
    t.erase(unique(all(t)), t.end());
    m = t.size();
 
    for (int i = 0; i < n; i++) a[i] = lower_bound(all(t), a[i]) - t.begin();

    for (int i = 0; i < k - 1; i++) update(a[i], 1);
    for (int i = k - 1; i < n; i++) {
        update(a[i], 1);

        int j = i - k + 1;
        auto [sum_left, mid] = get_kth((k + 1) / 2);

        int val = t[mid];

        ll total = sum[1];
        ll sum_right = total - sum_left;

        int cnt_L = (k + 1) / 2;
        int cnt_R = k - cnt_L;

        cout << (1ll * cnt_L * val - sum_left) + (sum_right - 1ll * cnt_R * val) << ' ';

        update(a[j], -1);
    }
    
    return 0;
}
