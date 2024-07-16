#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const int N = 2e5 + 5;

int a[N];
ll FT[N];
 
void update(int i, ll x) {
    for (; i < N; i += i & -i) FT[i] += x;
}
ll sum(int i) {
    ll sa = 0;
    for (; i; i -= i & -i) sa += FT[i];
    return sa;
}
 
int main() {
    int n,q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) update(i, a[i] - a[i - 1]);
    while(q--) {
        int op; cin >> op;
        if (op == 1) {
            int a,b,u;
            cin >> a >> b >> u;
            update(a,u);
            update(b + 1, -u);
        }
        else {
            int k;
            cin >> k;
            cout << sum(k) << '\n';
        }
    }
    return 0;
}
