#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

using ll = long long;
using ull = unsigned long long;

ull mul(ull a, ull b, ull M) {
	ll ret = a * b - M * ull(1.L / M * a * b);
	return ret + M * (ret < 0) - M * (ret >= (ll)M);
}

ull bpow(ull a, ull e, ull mod) {
	ull r = 1;
    for (; e; a = mul(a, a, mod), e >>= 1) {
        if (e & 1) r = mul(r, a, mod);
    }
	return r;
}

bool is_prime(ull n) { // miller rabin
	if (n < 2 or n % 6 % 4 != 1) return n - 2 < 2;
	ull s = __builtin_ctzll(n - 1), d = n >> s;
	for (ull a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
		ull p = bpow(a % n, d, n), i = s;
		while(p != 1 and p != n - 1 and a % n and i--) p = mul(p, p, n);
		if (p != n - 1 and i != s) return 0;
	}
	return 1;
}

int main() {
    int t; cin >> t;
    while(t--) {
        ll n; cin >> n;
        n++;
        while(!is_prime(n)) n++;
        cout << n << "\n";
    }
	return 0;
}
