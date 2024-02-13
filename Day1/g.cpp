#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>>a;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a.push_back({x, y});
    }
    sort(a.begin(), a.end(), [](auto a, auto b) {return a.first < b.first;});
    vector<ll>s(n + 1);
    for (int i = 0; i < n; i++) {
        s[i + 1] = s[i] + a[i].second;
    }
    if (a[n - 1].first - s[n] <= m) {
        cout << s[n] + m << "\n";
    }
    else {
        for (int i = n - 2; i >= 0; i--) {
            if (a[i].first == a[i + 1].first)continue;
            else {
                if (a[i].first - s[i + 1] <= m) {
                    cout << s[i + 1] + m << "\n";
                    return ;
                }
            }
        }
        cout << m << "\n";
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