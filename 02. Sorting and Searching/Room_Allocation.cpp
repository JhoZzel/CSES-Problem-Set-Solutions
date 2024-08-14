#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define ff first
#define ss second
 
int main() {
    int n; cin >> n;
    vector<tuple<int,int,int>> a;
    for (int i = 0; i < n; i++) {
        int L,R;
        cin >> L >> R;
        a.emplace_back(L, R, i);
    }
    sort(all(a));
    multiset<pair<int,int>> ms; // R - room_id
    int k = 0;
    vector<int> rooms(n);
    for (auto [L, R, i] : a) {
        if (ms.empty() or L <= ms.begin()->ff) {
            ms.emplace(R, k);
            rooms[i] = k;
            k++;
        }
        else {
            int room = ms.begin()->ss;
            ms.erase(ms.begin());
            ms.emplace(R, room);
            rooms[i] = room;
        }
    }
    cout << k << "\n";
    for (int e : rooms) cout << e + 1 << " ";
    
    return 0;
}
