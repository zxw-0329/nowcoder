/*
  dp[i][0]:为不为0开头（开头为[1...9]） 以x结尾的形成的序列总个数
  dp[i][1]:为不为0开头（开头为[1...9]） 以[0，2，4，6，8]结尾的形成的序列总个数
  对于第i的字符可以选择放和不放
  dp[i][0]=2*dp[i-1][0]
  if s[i]%2==0 dp[i][1]=dp[i-1][0]+dp[i-1][1]
  else dp[i][1]=dp[i-1][1];

  if s[i]!='0' dp[i][0]+=1;
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9+7;
int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
   int n;
   cin >> n;
   string s;
   cin >> s;
   vector<vector<ll>>dp(n, vector<ll>(2));
   ll ans = 0;
   for (int i = 0; i < n; i++) {
      if ((s[i] - '0') % 2 == 0)ans++;
   }
   dp[0][0] = s[0] != '0';
   for (int i = 1; i < n; i++) {

      dp[i][0] = (2 * dp[i - 1][0]) % mod;
      dp[i][1] = dp[i - 1][1];
      if ((s[i] - '0') % 2 == 0) {
         dp[i][1] = (dp[i][1] + dp[i - 1][0]) % mod;
      }
      if (s[i] != '0') {
         dp[i][0] = (dp[i][0] + 1) % mod;
      }
   }
    cout<<(ans+dp[n-1][1]);
   return 0;
}
