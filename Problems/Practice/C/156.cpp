// B. Travel Card  CF # 8VC Final round
// dp[i] = optimal cost till time = t[i]
// at a given time calculate cost of all 3 options availabls using answer for prev times
#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll n; cin >> n;
	vector<ll> times(n + 1), prefix_time(n + 1);
	times[0] = 0;prefix_time[0] = 0;
	for(int i=1;i<=n;i++)cin >> prefix_time[i];

	vector<ll> dp(n + 1);
	dp[0] = 0;
	for(int i=1;i<=n;i++){
		ll ans1 = dp[i - 1] + 20;
		ll ans2 = 1e18, ans3=1e18;
		ll index2, index3;
		
		if(prefix_time[i] - prefix_time[1] < 90)ans2 = 50;
		else{
			index2 = upper_bound(prefix_time.begin(), prefix_time.end(), prefix_time[i] - 90 ) - prefix_time.begin();
			ans2 = dp[index2 - 1] + 50;			
		}

		if(prefix_time[i] - prefix_time[1] < 1440)ans3 = 120;
		else{
			index3 = upper_bound(prefix_time.begin(), prefix_time.end(), prefix_time[i] - 1440) - prefix_time.begin();
			ans3 = dp[index3 - 1] + 120;
		}
		dp[i] = min(min(ans2,ans3), ans1);
	}
	for(int i=1;i<=n;i++){
		cout << (dp[i] - dp[i-1]) << " ";
	}
	cout << endl;
}