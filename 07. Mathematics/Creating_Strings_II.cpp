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

const int N = 1e6 + 6;

int F[N];
int Fi[N];

int comb(int n, int k) {
    return 1ll * F[n] * Fi[k] % MOD * Fi[n - k] % MOD;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    F[0] = 1;
    for (int i = 1; i < N; i++) F[i] = mul(i, F[i - 1]);
    Fi[N - 1] = bpow(F[N - 1], MOD - 2);
    for (int i = N - 2; i >= 0; i--) Fi[i] = mul(i + 1, Fi[i + 1]);

    string s; cin >> s;

    int freq[26] = {};
    for (char c : s) freq[c - 'a'] += 1;

    int n = s.size();
    int ans = F[n];
    for (int i = 0; i < 26; i++) {
        ans = mul(ans, Fi[freq[i]]);
    }
    cout << ans << "\n";

    return 0;
}
