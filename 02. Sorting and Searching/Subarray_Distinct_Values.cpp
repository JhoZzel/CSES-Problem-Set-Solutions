#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n,k;
int a[N];
int t[N];
int nxt[N];
map<int,int> last;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    memset(nxt ,-1, sizeof(nxt));
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = n; i >= 1; i--) {
        if (last.count(a[i])) {
            nxt[i] = last[a[i]];
            t[nxt[i]] = 0;
        }
        t[i] = 1;
        last[a[i]] = i;
    }
    long long ans = 0;
    int len = 0;
    int j = 1;
    while(j <= n and len + t[j] <= k) len += t[j++];
    for (int i = 1; i <= n; i++) {
        ans += j - i;
        len--;
        if (~nxt[i]) {
            t[nxt[i]] = 1;
            if (nxt[i] < j) len++;
        }
        while(j <= n and len + t[j] <= k) len += t[j++];
    }
    cout << ans << '\n';
    return 0;
}
