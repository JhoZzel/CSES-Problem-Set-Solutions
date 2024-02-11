#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)
using namespace std;

const int N = 1e3 + 5;

char par[N][N];
int level[N][N];
int G[N][N];

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

char dir[] = {'D', 'U', 'R', 'L'};

int main() {
    fast_io;
    int n,m;
    cin >> n >> m;
    int ini_i, ini_j;
    int fin_i, fin_j;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c; cin >> c;
            if (c == '#') continue;
            if (c == 'A') ini_i = i, ini_j = j;
            if (c == 'B') fin_i = i, fin_j = j;
            G[i][j] = 1;
        }
    }
    
    queue<pair<int,int>> Q;
    for (int i = 0; i < n; i++) fill(level[i], level[i] + m, -1);
    Q.emplace(ini_i, ini_j);
    level[ini_i][ini_j] = 0;
    par[ini_i][ini_j] = 'X';

    while(!Q.empty()) {
        int i,j;
        tie(i,j) = Q.front();
        Q.pop();
        for (int k = 0; k < 4; k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];
            if (ni < 0 or nj < 0) continue;
            if (ni >= n or nj >= m) continue;
            if (G[ni][nj] == 0 or level[ni][nj] != -1) continue;
            level[ni][nj] = 1 + level[i][j];
            par[ni][nj] = dir[k];
            Q.emplace(ni,nj);
        }
    }
 
    if (level[fin_i][fin_j] == -1) {
        cout << "NO\n";
        return 0;
    }
    
    string ans;
    int i = fin_i;
    int j = fin_j;
    while(par[i][j] != 'X') {
        ans += par[i][j];
        switch(par[i][j]) {
            case 'U': i++; break;
            case 'D': i--; break;
            case 'L': j++; break;
            case 'R': j--; break;
        }
    }
    reverse(ans.begin(), ans.end());
    
    cout << "YES\n";
    cout << ans.size() << "\n";
    cout << ans << "\n";

    return 0;
}
