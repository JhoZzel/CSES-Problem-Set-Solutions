#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int mul(int a, int b) { return 1ll * a * b % MOD; }
int bpow(int a, int e) {
    int r = 1;
    while(e) {
        if (e & 1) r = mul(r, a);
        a = mul(a, a);
        e >>= 1;
    }
    return r;
}

int main() {
    int q; cin >> q;
    while(q--) {
        int a,e;
        cin >> a >> e;
        cout << bpow(a, e) << '\n';
    }
    return 0;
}
