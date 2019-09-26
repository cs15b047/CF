#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ll n, m; scanf("%lld%lld",&n, &m);
	vector<ll> a(n);for(int i = 0;i < n;i++)scanf("%lld",&a[i]); for(int i = 0;i < n;i++)a[i] = a[i] % (m);
	if(false)printf("YES\n");
	else{
		vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, 0));
		bool possible = false;
		dp[0][0] = 1;
		for(int j = 1;j <= n;j++){
			for(int i = 0;i < m+1;i++){
				if(i == 0 && dp[(i - a[j - 1] + (m)) % (m) ][j - 1] == true)possible = true;
				dp[i][j] = dp[(i - a[j - 1] + (m)) % (m) ][j - 1] || dp[i][j - 1];
			}
		}
		// for(int i=0;i < m;i++){
		// 	for(int j = 0;j <= n;j++)cout << dp[i][j] << " ";
		// 	cout << endl;
		// }
		printf("%s\n", ((dp[0][n] && possible) ? "YES" : "NO"));
	}
}