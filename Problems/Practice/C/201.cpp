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
	// for(int i=1;i<=n;i++)cout << dp[i] <<" " ; cout << endl;
	cout << dp[n + 1] << endl;
}