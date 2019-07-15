// E. Let's Go Rolling! CF# 38 - 2
// dp[i, 0/1] = Ending ith marble in unpinned/pinned state 
// dp[i, 1] = min(dp[i - 1, 0], dp[i - 1, 1])
// dp[i, 0] = min(over j)(dp[j, 1] + sum(k = i to j + 1)(dist(k to j))) .. Basically pick locn of prev pinned one
#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll n; cin >> n;
	vector<pair<ll,ll>> pts(n);for(int i=0;i<n;i++)cin >> pts[i].first >> pts[i].second;
	sort(pts.begin(),pts.end());
	vector<vector<ll>> dp(n, vector<ll>(2, 1e18));
	dp[0][1] = pts[0].second;
	for(int i=1;i<n;i++){
		ll ans1 = 1e18, dist = 0, ans2 =1e18;
		for(int j = i - 1;j >= 0;j--){
			dist = dist + ((ll)(i - j)) * (pts[j + 1].first - pts[j].first) ;
			ans1 = min(ans1, dp[j][1] + dist);
		}
		dp[i][0] = ans1;
		ans2 = min(dp[i - 1][0], dp[i - 1][1]) + pts[i].second;
		dp[i][1] = ans2;
	}
	cout << min(dp[n - 1][0], dp[n - 1][1]) << endl;
}