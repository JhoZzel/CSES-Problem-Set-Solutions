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
    
    for (int i = 0; i < n; i++) {
        int target = x - a[i];
        if (target <= 0) continue;
        for (int j : M[target]) {
            if (j == i) continue;
            cout << i + 1 << " " << j + 1 << "\n";
            return 0;
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}
