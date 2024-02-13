#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, q, t;
    cin >> n >> q >> t;
    vector<int>a(n);
    vector<ll>s(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        s[i + 1] = s[i] + a[i];
    }
    // while (q--) { //解法一 O(q*long(n))
    //     ll  m;
    //     cin >> m;
    //     int l = 1, r = n;
    //     while (l <= r) {
    //         int mid = (l + r) / 2;
    //         ll p = (n - mid + 1) * t + s[n];
    //         if (p - s[n] <= m) {
    //             r = mid - 1;
    //         }
    //         else l = mid + 1;
    //     }
    //     if (l == n + 1) {
    //         cout << s[n] + t << "\n";
    //     }
    //     else cout << s[l - 1] + t << "\n";
    // }
    while (q--) { //O(q)
        ll m;
        cin >> m;
        int p = min(n * 1LL, m / t);
        cout << s[n - p] + t << "\n";
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    //  cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}