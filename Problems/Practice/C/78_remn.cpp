#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll n;scanf("%lld",&n);
	vector<ll>a(n);for(int i=0;i<n;i++)scanf("%lld",&a[i]);
	vector<map<ll,ll>>maps(n);
	vector<ll>dp(n);
	dp[0]=1;
	maps[0][-1] = 1;
	for(int i=1;i<n;i++){
		maps[i].clear();
		dp[i] =0;
		for(int j=0;j<i;j++){
			maps[i][a[j]] = max(maps[j][a[i]] + 1,(ll)2);
			dp[i] = max(dp[i], maps[i][a[j]]);
		}
	}
	ll ans = 1;
	for(auto it:dp)ans = max(ans, it);
	cout << ans<< endl;
}