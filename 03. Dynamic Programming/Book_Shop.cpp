#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, x;
    cin >> n >> x;
    vector<int> h(n), s(n);
    for (int &e : h) cin >> e;
    for (int &e : s) cin >> e;
    vector<int> last(x + 1);
    for (int pos = 0; pos < n; ++pos) {
        vector<int> cur(x + 1);
        for (int cap = 0; cap <= x; ++cap) {
            cur[cap] = last[cap];
            if (cap >= h[pos]) cur[cap] = max(last[cap], last[cap - h[pos]] + s[pos]);
        }
        swap(last, cur);
    }
    cout << last[x] << "\n";
    return 0;
}
