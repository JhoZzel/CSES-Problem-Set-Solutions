#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 6;

int n;
int cnt[MAX];
int freq[MAX];

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        freq[x]++;
    }
    for (int i = 1; i < MAX; i++) {
        for (int j = i; j < MAX; j += i) {
            cnt[i] += freq[j];
        }
    }
    int ans = 1;
    for (int i = 1; i < MAX; i++) {
        if (cnt[i] > 1) ans = i;
    }
    cout << ans << '\n';
    return 0;
}
