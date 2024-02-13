#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n, m;
int ans = 20;
void dfs(int k, vector<int>&a, vector<pair<int, int>>&b) {

    if (k >= m) {
        int t = 0;
        for (int i = 1; i < n; i++) {
            if (a[i] > a[0])t++;
        }
        ans = min(ans, t + 1);
        return ;
    }
    int i = b[k].first;
    int j = b[k].second;
    if (i == 0 || j == 0) {
        a[0] += 3;
        dfs(k + 1, a, b);
        a[0] -= 3;
    }
    else {
        a[i] += 3;
        dfs(k + 1, a, b);
        a[i] -= 3;
        a[j] += 3;
        dfs(k + 1, a, b);
        a[j] -= 3;
        a[i]++, a[j]++;
        dfs(k + 1, a, b);
        a[i]--, a[j]--;
    }
}
void solve() {
    //int n,m;
    ans = 20;
    cin >> n >> m;
    vector<int>a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<pair<int, int>>b;
    for (int i = 0; i < m; i++) {
        int x, y;

        cin >> x >> y;
        x--; y--;
        b.push_back({x, y});
    }
    dfs(0, a, b);
    cout << ans << "\n";
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