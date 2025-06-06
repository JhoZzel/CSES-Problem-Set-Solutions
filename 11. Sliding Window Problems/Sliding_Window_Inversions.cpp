#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()

using ll = long long;

const int N = 2e5 + 5;

int FT[N];
void update(int i, int x) {
    for (++i; i < N; i += i & -i) FT[i] += x;
}
int sum(int i) {
    int sa = 0;
    for (++i; i > 0; i -= i & -i) sa += FT[i];
    return sa;
}
int query(int l, int r) {
    return sum(r) - sum(l - 1);
}

int n,k;
int a[N];
vector<int> t;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        t.push_back(a[i]);
    }

    sort(all(t));
    t.erase(unique(all(t)), t.end());
 
    for (int i = 0; i < n; i++) {
        a[i] = lower_bound(all(t), a[i]) - t.begin();
    }

    ll ans = 0;
    for (int i = 0; i < k - 1; i++) {
        ans += query(a[i] + 1, N - 1);
        update(a[i], 1);
    }
    for (int i = k - 1; i < n; i++) {
        int j = i - k + 1;
        ans += query(a[i] + 1, N - 1);
        cout << ans << ' ';
        update(a[i], 1);
        ans -= query(0, a[j] - 1);
        update(a[j], -1);
    }
    
    return 0;
}
