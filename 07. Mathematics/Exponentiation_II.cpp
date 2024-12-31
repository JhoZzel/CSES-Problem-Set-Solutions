#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int mul(int a, int b, int mod) { return 1ll * a * b % mod; }
int bpow(int a, int e, int mod) {
    int r = 1;
    while(e) {
        if (e & 1) r = mul(r, a, mod);
        a = mul(a, a, mod);
        e >>= 1;
    }
    return r;
}

int main() {
    int q; cin >> q;
    while(q--) {
        int a,b,c;
        cin >> a >> b >> c;
        int e = bpow(b, c, MOD - 1);
        cout << bpow(a, e, MOD) << '\n';
    }
    return 0;
}
