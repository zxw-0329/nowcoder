#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int x, y, r;
        cin >> x >> y >> r;
        sum += abs(x) + abs(y);
    }
    if (sum > 90 * n) {
        cout << "bit-noob\n";
    }
    else cout << "buaa-noob\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}