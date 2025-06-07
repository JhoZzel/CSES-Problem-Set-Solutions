#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long k;
    cin >> n >> k;
    int j = n - 1;
    int idx = 1;
    vector<int> a(n, -1);
    while(k) {
        if (k > n - idx) {
            k -= n - idx;
            a[j--] = idx++;
        } else {
            a[k] = idx++;
            break;
        }
    }
    for (int i = 0; i < n; i++) if (a[i] == -1) a[i] = idx++;
    for (int i = 0; i < n; i++) cout << a[i] << " ";

    return 0;
}
