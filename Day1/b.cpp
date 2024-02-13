#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {//模拟+特判;
    int n;
    cin >> n;
    vector<int>a[2];
    map<int, int>m1;
    map<int, int>m2;
    int cl = 0, cr = 0;
    int dl = 0, dr = 0;
    for (int i = 0; i < n; i++) {
        int  x, y; cin >> x >> y;
        if (x == 1) {
            a[0].push_back(y);
            m1[y] = 1;
            if (y > 0)cr = 1;
            else cl = 1;
        }
        else {
            a[1].push_back(y);
            m2[y] = 1;
            if (y > 0)dr = 1;
            else if (y < 0)dl = 1;
        }
    }
    if (a[0].empty() && a[1].empty()) {
        cout << 3 << "\n";
        return ;
    }
    sort(a[0].begin(), a[0].end());
    sort(a[1].begin(), a[1].end());
    bool lx = false, rx = false;
    for (auto x : a[0]) {
        if (x < 0) {
            if (m2[x] || m2[x - 1] || m2[x + 1])lx = true;
        }
        else  if (m2[x] || m2[x - 1] || m2[x + 1])rx = true;
    }
    if (lx && rx) {
        cout << 0 << "\n";
    }
    else if (lx) {
        if (m2[0] || m1[1] || cr || dr) {
            cout << 1 << "\n";
        }
        else cout << 2 << "\n";
    }
    else if (rx) {
        if (m2[0] || m1[-1] || cl || dl) {
            cout << 1 << "\n";
        }
        else cout << 2 << "\n";
    }
    else {
        if (m1[1] && m1[-1]) {
            cout << 1 << "\n";

        }
        else if (m1[1] || m1[-1] || m2[0]) {
            cout << 2 << "\n";
        }
        else {
            if ((cl && !cr && !dl && !dr) || (!cl && cr && !dl && !dr) || (!cl && !cr && dl && !dr) || (!cl && !cr && !dl && dr) || (cl && !cr && dl && !dr) || (!cl && cr && !dl && dr)) {
                cout << 3 << "\n";
            }
            else cout << 2 << "\n";
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}