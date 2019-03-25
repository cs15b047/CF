#include <bits/stdc++.h>
using namespace std ;

typedef long long int ll ;
ll mod = 1e9+7 ;

int main(int argc, char const *argv[])
{
	int n,k;cin>>n>>k ;

	vector<vector<ll>> factors(n+1),dp(k+1) ;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j*j <= i; ++j){
			if (i % j == 0)
			{
				factors[i].push_back(j) ;
				if (j*j != i)factors[i].push_back(i/j) ;
			}
		}
	}

	ll ans = 0 ;
	for (int i = 1; i <= n; ++i){
		dp[1].resize(n+1) ;
		dp[1][i] = 1 ;
		if (1==k)ans = (ans + dp[1][i]) % mod ;
	}
		
	for(int i=2;i<=k;i++){
		dp[i].resize(n+1) ;
		for(int j=1;j<=n;j++){
			dp[i][j] = 0 ;
			for(auto it: factors[j])dp[i][j] = (dp[i][j] + dp[i-1][it]) % mod ;
			if (i==k)ans = (ans + dp[i][j]) % mod ;
		}
	}
	cout << ans ;



	return 0;
}