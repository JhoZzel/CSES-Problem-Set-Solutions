#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 5;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int &e : a) cin >> e;
    vector<int> d(n + 1, INF);
    d[0] = -INF;
    for (int i = 0; i < n; i++) {
        int l = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
        if (d[l - 1] < a[i] and a[i] < d[l]) {
            d[l] = a[i];
        }
    }
    int LIS = n;
    while(d[LIS] >= INF) LIS--;
    cout << LIS << "\n";
    return 0;
}
