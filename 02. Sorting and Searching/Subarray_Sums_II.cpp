#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const int N = 2e5 + 5;
 
int n;
int S;
ll pre[N];

ll merge(int l, int r) {
    int mid = (l + r) / 2;
    ll cnt = 0;
    for (int i = l; i <= mid; i++) {
        int L = lower_bound(pre + mid + 1, pre + r + 1, S + pre[i]) - (pre + mid + 1);
        int R = upper_bound(pre + mid + 1, pre + r + 1, S + pre[i]) - (pre + mid + 1) - 1;
        cnt += R - L + 1;
    }
    vector<ll> tmp(r - l + 1);
    merge(pre + l, pre + mid + 1, pre + mid + 1, pre + r + 1, tmp.begin());
    for (int i = l; i <= r; i++) pre[i] = tmp[i - l];
    return cnt;
}

ll f(int l, int r) {
    if (l == r) return 0;
    int mid = (l + r) / 2;
    return f(l, mid) + f(mid + 1, r) + merge(l, r);
}

int main() {
    cin >> n >> S;
    for (int i = 1; i <= n; i++) {
        cin >> pre[i];
        pre[i] += pre[i - 1];
    }
    cout << f(0, n) << '\n';
    return 0;
}
