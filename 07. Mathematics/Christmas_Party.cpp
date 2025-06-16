#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MOD = 1e9 + 7;

int add(int a, int b) { return (a + b) % MOD; }
int mul(int a, int b) { return 1ll * a * b % MOD; }
int bpow(int a, int e) {
    int r = 1;
    while(e){
        if (e & 1) r = mul(r, a);
        a = mul(a, a);
        e >>= 1;
    }
    return r;
}
int inv(int a) { return bpow(a, MOD - 2); }

const int N = 1e6 + 6;

int D[N]; // Derangement

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    D[1] = 0;
    D[2] = 1;
    for (int i = 3; i < N; i++) D[i] = mul(i - 1, add(D[i - 1], D[i - 2]));

    int n; cin >> n;
    cout << D[n] << "\n";

    return 0;
}
