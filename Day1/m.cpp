#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    int cnt = n / 6;
    if (n % 6 == 0) {
        cout << cnt << "\n";
        return ;
    }
    cnt++;
    n -= 6;
    cnt += n / 6;
    cout << cnt << "\n";
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