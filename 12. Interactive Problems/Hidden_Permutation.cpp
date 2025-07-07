#include <bits/stdc++.h>
using namespace std;

const int N = 1000 + 5;

int n;
int a[N];
int p[N];

bool ask(int i, int j) {
    cout << "? " << i << " " << j << endl;
    string q; cin >> q;
    return (q == "YES");
}

void solve(int l, int r) {
    if (l == r) return;
    int mid = (l + r) / 2;
    solve(l, mid);
    solve(mid + 1, r);

    int i = l;
    int j = mid + 1;
    vector<int> order;
    while(i <= mid and j <= r) {
        if (i > mid or j > r) break;
        if (ask(a[i], a[j])) order.push_back(a[i++]);
        else order.push_back(a[j++]);
    }
    while(i <= mid) order.push_back(a[i++]);
    while(j <= r) order.push_back(a[j++]);
    for (int i = r; i >= l; i--) {
        a[i] = order.back();
        order.pop_back();
    }
}

int main() {
    cin >> n;
    iota(a, a + N, 0);
    solve(1, n);
    for (int i = 1; i <= n; i++) p[a[i]] = i;
    cout << "! ";
    for (int i = 1; i <= n; i++) {
        cout << p[i] << " \n"[i == n];
    }
    return 0;
}
