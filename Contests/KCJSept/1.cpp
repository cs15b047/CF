#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll t; scanf("%lld",&t);
	for(int q = 0;q < t;q++){
		ll n, k; scanf("%lld%lld",&n, &k);
		vector<ll> a(n);for(int i=0;i < n;i++)scanf("%lld",&a[i]);
		vector<vector<ll>> cost(n, vector<ll>(n, 0));

		for(int i = 0;i < n;i++){
			for(int j = i + 1; j < n;j++){
				map<ll, ll> cnt;
				for(int x = i;x <= j;x++)cnt[a[x]]++;
				ll mxm = 1;for(auto it:cnt)mxm = max(mxm, it.second); //maj
				cost[i][j] = (j - i + 1) - mxm;
			}
		}

		vector<vector<ll>> dp(n, vector<ll>(k + 1, 1e9));
		for(int i = 0;i < n;i++)dp[i][0] = cost[0][i];

		for(int j = 1;j <= k; j++){
			for(int i = 0;i < n;i++){
				dp[i][j] = cost[0][i];
				for(int x = 0;x < i;x++){
					dp[i][j] = min(dp[x][j - 1] + cost[x + 1][i], dp[i][j]);
				}
			}
		}
		printf("Case #%d: %lld\n", q + 1, dp[n - 1][k]);
	}
}