#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)
using namespace std;

const int N = 1e3 + 5;

int n;
int m;
bool vis[N][N];
int G[N][N];

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

void DFS(int i, int j) {
    vis[i][j] = true;
    for (int k = 0; k < 4; k++) {
        int ni = i + dx[k];
        int nj = j + dy[k];
        if (ni < 0 or nj < 0) continue;
        if (ni >= n or nj >= m) continue;
        if (G[ni][nj] == 0 or vis[ni][nj]) continue;
        DFS(ni, nj);
    }
}

void solve() {
    int rooms = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (G[i][j] == 0 or vis[i][j]) continue;
            DFS(i,j);
            rooms++;
        }
    }    
    cout << rooms << "\n";
}

int main() {
    fast_io;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c; cin >> c;
            if (c != '.') continue;
            G[i][j] = 1;
        }
    }
    solve();
    return 0;
}
