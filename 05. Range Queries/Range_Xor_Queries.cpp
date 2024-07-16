#include <bits/stdc++.h>
using namespace std;
 
const int N = 2e5 + 5;
 
int FT[N];
 
void update(int i, int x) {
    for (; i < N; i += i & -i) FT[i] ^= x;
}
int Xor(int i) {
    int x = 0;
    for (; i; i -= i & -i) x ^= FT[i];
    return x;
}
int query(int l, int r) {
    return Xor(r) ^ Xor(l - 1);
}
 
int main() {
    int n,q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        update(i, x);
    }
    while(q--) {
        int l,r;
        cin >> l >> r;
        cout << query(l, r) << '\n';
    }
    return 0;
}
