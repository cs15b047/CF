#include <bits/stdc++.h>
using namespace std ;

typedef long long int ll ;
ll mod = 1e9+7;
int main(int argc, char const *argv[])
{
	ll n,k,d;cin >>n>>k>>d;
	ll ans = 0 ;
	if(k == 1)ans = 1 ;

	vector<vector<ll>>dp(n+1);for(int i=0;i<=n;i++)dp[i].resize(k+1);
	for(int i=1;i<=k;i++){dp[1][i] = 1 ;dp[0][i] = 1 ;}
	for(int i=0;i<=n;i++){dp[i][0] = 0 ;dp[i][1] = 1;}

	for(int i=2;i<=n;i++){
		for(int j=1;j<=k;j++){
			dp[i][j] = 0 ;
			for(int l=1;l<=min(j,i);l++){
				dp[i][j]  = (dp[i][j] + dp[i-l][j]) % mod ;
			}
		}
	}
	if(k != 1)
		ans = (dp[n][k] - dp[n][d-1] + mod) % mod ;			

	cout << ans <<endl ;

	return 0;
}