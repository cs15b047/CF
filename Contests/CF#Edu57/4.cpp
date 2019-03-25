#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll n; cin >> n;
	string str; cin >> str ;
	vector<ll> cost(n); for(int i=0;i<n;i++)cin >> cost[i] ;

	vector<vector<ll>> dp(n, vector<ll>(4, 1e18));
	for(int i=0;i<n;i++){
		if(i == 0)dp[i][0] = (str[i] == 'h') * cost[i] ;
		else dp[i][0] = dp[i - 1][0] +  (str[i] == 'h') * cost[i] ;
		// cout << dp[i][0] << " ";
	}
	// cout << endl ;

	for(int i=0;i<n;i++){
		// cout << i << endl ;
		if((i == 0) && (str[i] == 'h'))dp[i][1] = 0;
		else if(i != 0){
			ll ans1 = 1e18,ans2=1e18;
			if(dp[i - 1][1] < 1e18)ans1 = dp[i - 1][1] + (str[i] == 'a') * cost[i] ;
			if(dp[i - 1][0] < 1e18 && str[i] == 'h')ans2 = dp[i - 1][0] ;
			dp[i][1] = min(ans1, ans2);
		}
		// cout << dp[i][1] << " ";
	}
	// cout << endl;

	for(int i=1;i<n;i++){
		ll ans1 = 1e18,ans2=1e18;
		if(dp[i - 1][2] < 1e18)ans1 = dp[i - 1][2] + (str[i] == 'r') * cost[i] ;
		if(dp[i - 1][1] < 1e18 && str[i] == 'a')ans2 = dp[i - 1][1] ;
		dp[i][2] = min(ans1, ans2);
		// cout << dp[i][2] << " ";
	}
	// cout << endl ;

	for(int i=2;i<n;i++){
		ll ans1 = 1e18,ans2=1e18;
		if(dp[i - 1][3] < 1e18)ans1 = dp[i - 1][3] + (str[i] == 'd') * cost[i] ;
		if(dp[i - 1][2] < 1e18 && str[i] == 'r')ans2 = dp[i - 1][2] ;
		dp[i][3] = min(ans1, ans2);
		// cout << dp[i][3] << " ";
	}
	// cout << endl ;

	ll answer = min(min(dp[n - 1][0], dp[n - 1][1]), min(dp[n - 1][2], dp[n - 1][3])) ;

	cout << answer << endl ;
}