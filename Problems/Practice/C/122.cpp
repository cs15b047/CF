//C. George and Job -- #267 - 2
//Dp[n, k] = Max sum value where kth interval ends at n = (Dp[n - m, k -1] + sum((n-m+1):n), Dp[n -1, k])
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll n, m, k; cin >> n >> m >> k;
	vector<ll> p(n+1),prefix_sum(n+1);for(int i=1;i<=n;i++)cin >> p[i];
	vector<vector<ll>> dp(n+1);for(int i=0;i<=n;i++)dp[i].resize(n+1);
	prefix_sum[0] = 0;for(int i=1;i<=n;i++)prefix_sum[i] = prefix_sum[i-1] + p[i];

	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=k;j++){
			if(i < m*j)dp[i][j] = 0;
			else if(i == m*j)dp[i][j] = prefix_sum[i];
			else{
				dp[i][j] = max( dp[i - 1][j], dp[i - m][j - 1] + (prefix_sum[i] - prefix_sum[i - m]) );
			}
		}
	}
	cout << dp[n][k] << endl ;

}