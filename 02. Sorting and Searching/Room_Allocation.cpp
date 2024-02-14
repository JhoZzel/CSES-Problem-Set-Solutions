#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<tuple<int,int,int>> a;
    for (int i = 0; i < n; i++) {
        int L,R;
        cin >> L >> R;
        a.emplace_back(L, R, i);
    }
    sort(a.begin(), a.end());

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;    
    int k = 0;
    vector<int> rooms(n);
    for (auto [L, R, i] : a) {
        if (pq.empty() || L <= pq.top().first) {
            pq.emplace(R, k);
            rooms[i] = k;
            k++;
        }
        else {
            int room = pq.top().second;
            pq.pop();
            pq.emplace(R, room);
            rooms[i] = room;
        }
    }
    cout << k << "\n";
    for (int r : rooms) cout << r + 1 << " ";

    return 0;
}
