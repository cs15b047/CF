// B. Long Path  CF# 239 - 1
// Going to (i + 1)th room once = (Go to ith room once (dp[i])) + (go from i to p[i] (1)) + (go from p[i] to i (dp[i] - dp[p[i]])) + (go from i to i + 1 (1))
// soln seen
#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;
ll mod = 1e9 + 7;
int main(){
	ll n; cin >> n;vector<ll>p(n + 1);for(int i=1;i<=n;i++)cin >> p[i];
	vector<ll> dp(n + 2, 0);
	dp[1] = 0;
	for(int i=1;i<=n;i++){
		dp[i + 1] = (dp[i] + 2 + dp[i] - dp[p[i]] + mod ) % mod;
	}
	cout << dp[n + 1] << endl;
}