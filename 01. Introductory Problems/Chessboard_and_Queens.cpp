#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n = 8;
vector<string> a(n);
vector<int> queens;

bool valid(int row, int col) {
    if (a[row][col] == '*') return 0;
    for (int c = 0; c < queens.size(); c++) {
        if (row == queens[c]) return 0;
        if (abs(row - queens[c]) == abs(col - c)) return 0;
    } 
    return 1;
}

int back(int col) {
    int ret = 0;
    if (col == n) return 1;
    for (int i = 0; i < n; i++) {
        if (not valid(i,col)) continue;
        queens.push_back(i);
        ret += back(col + 1);
        queens.pop_back();
    }
    return ret;
}

int main() {
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << back(0) << "\n";
    return 0;
}
