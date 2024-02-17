#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int>v(n), w(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i] >> w[i];
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if ((w[i] | m) == m)ans += v[i];
    }
    auto check = [&](int k)->void{
        ll res = 0;
        for (int i = 0; i < n; i++) {
            bool ok = true;
            for (int j = 29; j > k; j--) {
                if ((((m >> j) & 1) == 0) && (((w[i] >> j) & 1) == 1)) {
                    ok = false;
                    break;
                }
            }
            if (((w[i] >> k) & 1))ok = false;
            if (ok)res += v[i];
        }
        ans = max(ans, res);
    };

    for (int i = 29; i >= 0; i--) {
        if ((m >> i) & 1) {
            check(i);
        }
    }
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