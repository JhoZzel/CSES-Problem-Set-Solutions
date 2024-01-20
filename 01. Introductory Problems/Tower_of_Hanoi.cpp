#include <bits/stdc++.h>
using namespace std;

void hanoi(int from, int to, int k) {
    if (k == 0) return;
    int mid = 6 - from - to;
    hanoi(from, mid, k - 1);
    cout << from << " " << to << "\n";
    hanoi(mid, to, k - 1);
}

int main() {
    int n; cin >> n;
    cout << (1 << n) - 1 << "\n";
    hanoi(1,3,n);
    return 0;
}
