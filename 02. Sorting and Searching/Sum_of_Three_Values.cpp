#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,x;
    cin >> n >> x;
    map<int,vector<int>> M;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        M[a[i]].push_back(i);
    }
    vector<int> ord(a);
    sort(ord.begin(), ord.end());
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int target = x - a[i] - a[j];
            if (target < 0) continue;
            if (!binary_search(ord.begin(), ord.end(), target)) continue;
            for (int k : M[target]) {
                if (k == i || k == j) continue;
                cout << i + 1 << " " << j + 1 << " " << k + 1 << "\n";
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}
