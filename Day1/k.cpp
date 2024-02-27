#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 998244353;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int>a(n);
    vector<string>s(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> s[i];
        a[i]--;
    }
    vector<int>vis(n,-1);
    ll ans = 1;
    for (int i = 0; i < n; i++) {
        int j = i;
        while (vis[j] == -1) {
            vis[j] = i;
            j = a[j];
        }
        if (vis[j] == i) {
            int k = j;
            int len = 0;
            do {
                k = a[k];
                len++;
            } while (k != j);
            int res = 0;
            for (int x = 0; x < 5; x++) {
                int v = x;
                for (int l = 0; l < len; l++) {
                    v = s[k][v] - 'A';
                    k = a[k];
                }
                res += v == x;
            }
            ans = ans * res % mod;
        }
    }
    cout << ans << "\n";
    return 0;
}