#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 5;

ll FT[N];

void update(int i, ll x) {
    for (; i < N; i += i & -i) {
        FT[i] += x;
    }
}
ll sum(int i) {
    ll sa = 0;
    for (; i; i -= i & -i) sa += FT[i];
    return sa;
}
ll query(int l, int r) {
    return sum(r) - sum(l - 1);
}

int main() {
    int n,q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        update(i, x);
    }
    while(q--) {
        int op; cin >> op;
        if (op == 1) {
            int k,u;
            cin >> k >> u;
            update(k, u - query(k,k));
        }
        else {
            int a,b;
            cin >> a >> b;
            cout << query(a, b) << '\n';
        }
    }
    return 0;
}
