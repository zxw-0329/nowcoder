#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    double c, d, h, w;
    cin >> c >> d >> h >> w;
    printf("%.4f\n", (6 * w)*c / 2.0);
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