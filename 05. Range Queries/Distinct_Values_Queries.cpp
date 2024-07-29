#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int FT[N];
void update(int i, int x) {
    for (++i; i < N; i += i & -i) FT[i] += x;
}
int sum(int i) {
    int sa = 0;
    for (++i; i > 0; i -= i & -i) sa += FT[i];
    return sa;
}
int query(int l, int r) {
    return sum(r) - sum(l - 1);
}

int main() {
    int n,q;
    cin >> n >> q;
    vector<int> a(n);
    for (int &e : a) cin >> e;

    vector<array<int, 3>> Q(q);
    for (int i = 0; i < q; i++) {
        int l,r;
        cin >> l >> r;
        l--; r--;
        Q[i] = {l,r,i};
    }
    sort(Q.rbegin(), Q.rend());
    
    map<int,int> last;
    vector<int> ans(q);
    int j = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (last.count(a[i])) update(last[a[i]], -1);
        last[a[i]] = i;
        update(i, 1);
        while(j < q && Q[j][0] == i) {
            auto [l,r,id] = Q[j];
            ans[id] = query(i, r);
            j++;
        }
    }
    for (int i = 0; i < q; i++) {
        cout << ans[i] << ' ';
    }
    return 0;
}
