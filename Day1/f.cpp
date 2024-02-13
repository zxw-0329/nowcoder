#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
int qpow(int a, int b) {
    ll ans = 1;
    while (b) {
        if (b & 1)ans = (ll)ans * a % mod;
        a = (ll)a * a % mod;
        b >>= 1;
    }
    return ans % mod;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<ll>fac(m + 1);
    vector<ll>infac(m + 1);
    fac[0] = 1;
    for (int i = 1; i <= m; i++) {
        fac[i] = fac[i - 1] * 1LL * i % mod;
    }
    infac[m] = qpow(fac[m], mod - 2);
    for (int i = m; i >= 1; i--) {
        infac[i - 1] = infac[i] * 1LL * i % mod;
    }
    ll ans = 0;
    for (int i = 0; i <= m; i++) {
        ans = (ans + ((m - i) % 2 ? -1 : 1) * fac[m] * infac[i] % mod * infac[m - i] % mod * qpow(i, n) ) % mod;
    }
    ans = ans * infac[m] % mod;
    cout << (ans + mod) % mod << "\n";
    return 0;
}