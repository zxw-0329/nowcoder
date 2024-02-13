#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    //int F = 0, f = 0;
    // for (int i = 0; i < n - 2; i++) { //复杂度O(n^3*T)
    //     for (int j = i + 1; j < n - 1; j++) {
    //         for (int k = j + 1; k < n; k++) {
    //             if (s[i] == 'D' && s[j] == 'F' && s[k] == 'S') {
    //                 F = 1;
    //             }
    //             if (s[i] == 'd' && s[j] == 'f' && s[k] == 's') {
    //                 f = 1;
    //             }
    //         }
    //     }
    // }
    //cout << F << " " << f << "\n";
    for (auto t : {"DFS", "dfs"}) { //O(n*T)
        int k = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == t[k])k++;
        }
        cout << (k == 3) << " ";
    }
    cout << "\n";
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