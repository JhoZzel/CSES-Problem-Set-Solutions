#include <bits/stdc++.h>
using namespace std;
 
const int N = 2e5 + 5;
 
int n,m,k;
int a[N];
int T[4 * N];
vector<int> t;
 
void update(int pos, int x, int id = 1, int tl = 0, int tr = m - 1) {
    if (tl == tr) T[id] += x;
    else {
        int tm = (tl + tr) / 2;
        if (pos <= tm) update(pos, x, 2 * id, tl, tm);
        else update(pos, x, 2 * id + 1, tm + 1, tr);
        T[id] = T[2 * id] + T[2 * id + 1];
    }
}
 
int query(int k, int id = 1, int tl = 0, int tr = m - 1) {
    if (tl == tr) return tl;
    int tm = (tl + tr) / 2;
    if (k > T[2 * id]) 
        return query(k - T[2 * id], 2 * id + 1, tm + 1, tr);
    else 
        return query(k, 2 * id, tl, tm);
}
 
int get(int x) {
    int pos = lower_bound(t.begin(), t.end(), x) - t.begin();
    return pos;
}
 
int main() {
    cin.tie(0) -> sync_with_stdio(0);
 
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        t.push_back(a[i]);
    }
 
    sort(t.begin(), t.end());
    t.erase(unique(t.begin(), t.end()), t.end());
    m = t.size();
    
    for (int i = 0; i < k - 1; i++) update(get(a[i]), 1);
    for (int i = k - 1; i < n; i++) {
        update(get(a[i]), 1);
        cout << t[query((k + 1) / 2)] << ' ';
        update(get(a[i - k + 1]), -1);
    }
    
    return 0;
}
