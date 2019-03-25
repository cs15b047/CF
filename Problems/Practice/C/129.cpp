#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;
ll mod = 1e9+7;

int main(){
	ll n; cin >> n;
	vector<ll>dp(n+1),alt_prefix(n+1);
	dp[1] = 1;alt_prefix[1] = 1;
	dp[2] = 2;alt_prefix[2] = 1;
	
	for(ll i = 2; i <= n; i++){
		dp[i] = (1 + alt_prefix[i - 1]) % mod;
		alt_prefix[i] = (alt_prefix[i - 2] + dp[i]) % mod ;
	}
	ll answer = 0;
	for(ll i=1;i<=n;i++){
		answer = (answer + dp[i]) % mod ;
	}
	cout << answer << endl;
}