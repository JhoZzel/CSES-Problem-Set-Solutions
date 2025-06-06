#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int n,k;
    cin >> n >> k;
    vector<int> a(n), t;
    for (int &x : a) {
        cin >> x;
        t.push_back(x);
    }
    sort(all(t));
    t.erase(unique(all(t)), t.end());

    for (int i = 0; i < n; i++) {
        a[i] = lower_bound(all(t), a[i]) - t.begin();
    }

    int cnt = 0;
    vector<int> freq(n);
    for (int i = 0; i < k - 1; i++) cnt += (freq[a[i]]++ == 0);
    for (int i = k - 1; i < n; i++) {
        int j = i - k + 1;
        cnt += (freq[a[i]]++ == 0);
        cout << cnt << " ";
        cnt -= (--freq[a[j]] == 0);
    }

    return 0;
}
