#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false); cin.tie (NULL)
using namespace std;

const int N = 2e5 + 5;
const int LOG = 18;

int a[N];
int jmp[N][LOG];

int f(int a, int b) {
    return min(a,b);
}

void build() {
    for(int i = 0; i < N; i++) jmp[i][0] = a[i];
    for(int d = 1, p = 1; 2 * p < N; d++, p <<= 1) {
        for(int i = 0; i + 2 * p - 1 < N; i++) {
            jmp[i][d] = f(jmp[i][d - 1], jmp[i + p][d - 1]);
        }
    }
}

int query(int l, int r) {
    int d = r - l + 1;
    int k = 31 - __builtin_clz(d); 
    return f(jmp[l][k], jmp[r - (1 << k) + 1][k]);
}

int main() {
    int n,q; 
    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> a[i];
    build();
    while(q--) {
        int l,r;
        cin >> l >> r;
        l--; r--;
        cout << query(l,r) << "\n";
    }
    return 0;
}
