#include <bits/stdc++.h>
using namespace std;
 
const int N = 2e5 + 5;
 
int n;
int q;
int nc;
 
int id[N];
int dis[N];
int par[N];
int cycle_idx[N];
int color[N];
 
int timer;
int tin[N];
int tout[N];
vector<vector<int>> cycles;

int to[N];
vector<int> Gt[N];
 
void dfs(int u) { // find cycles
    color[u] = 1;
    for (int v : Gt[u]) {
        if (color[v] == 2) continue;
        if (color[v] == 1) {
            vector<int> cycle;
            int r = 0;
            for (int w = u; w != par[v]; w = par[w]) {
                cycle.push_back(w);
                id[w] = nc;
                cycle_idx[w] = r++;
            }
            cycles.push_back(cycle);
            nc++;
        } 
        else {
            par[v] = u;
            dfs(v);
        }
    }
    color[u] = 2;
}
 
void bfs(int idx) { // mark the branchs from my cycle
    queue<int> Q;
    for (int v : cycles[idx]) {
        Q.push(v);
        par[v] = v;
        dis[v] = 0;
    }
    while(!Q.empty()) {
        int u = Q.front(); Q.pop();
        for (int v : Gt[u]) {
            if (dis[v] != -1) continue;
            color[v] = 1;
            par[v] = par[u];
            dis[v] = dis[u] + 1;
            id[v] = idx;
            Q.push(v);
        }
    }
}
 
void dfs2(int u) { // mark the ancestor of every branch
    color[u] = 1;
    tin[u] = timer++;
    for (int v : Gt[u]) {
        if (color[v]) continue;
        dfs2(v);
    }
    tout[u] = timer++;
}
 
void mark_anc(int idx) {
    for (int p : cycles[idx]) color[p] = 1; //cycle
    for (int p : cycles[idx]) {
        timer = 0;
        dfs2(p);
    }
}

int dis_cycle(int u, int v) {
    int len = cycles[id[u]].size();
    int i = cycle_idx[u];
    int j = cycle_idx[v];
    return (j - i + len) % len;
}

bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] and tout[u] >= tout[v]; 
}
 
int query(int u, int v) {
    if (u == v) return 0;
    if (id[u] != id[v]) return -1; // diffente components
    int p1 = par[u], p2 = par[v];
    if (p1 == p2) return is_ancestor(v, u) ? dis[u] - dis[v] : -1; // same branch
    if (p1 != u and p2 != v) return -1; // different branchs 
    if (p2 == v) return dis_cycle(p1, v) + dis[u]; // branch-cycle or cycle-cycle
    return -1;
}
 
int main() {
    cin >> n >> q;
    for (int u = 0; u < n; u++) {
        int v; cin >> v;
        v--;
        to[u] = v;
        Gt[v].push_back(u);
    }
    
    // find th ecycles
    memset(par, -1, sizeof(par));
    for (int i = 0; i < n; i++) {
        if (color[i]) continue;
        par[i] = -1;
        dfs(i);
    }
    
    // bfs from every cycle
    memset(dis, -1, sizeof(dis));
    for (int i = 0; i < nc; i++) bfs(i);
    
    // get the ancestor of every branch 
    memset(color, 0, sizeof(color));
    for (int i = 0; i < nc; i++) mark_anc(i);
    
    while(q--) {
        int u,v;
        cin >> u >> v;
        u--; v--;
        cout << query(u,v) << '\n';
    }

    return 0;
}
