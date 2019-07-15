// C. Vladik and Memorable Trip   CF# 416 - 2
// Read question carefully: Either all people go and in 1 segment , otherwise no one goes
// dp[i] = Answer for 1st i people
// Go in reverse order for start locn, and locn j is valid if for all cities from j to i, city[j], city[j + 1].. city[i] have extremes(extreme locns in array) located in this range itself
#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;


int main(){
	ll n; cin >> n;
	vector<ll>city,dp;
	map<ll,vector<ll>> ele_idx;
	city.resize(n + 1);for(int i=1;i<=n;i++)cin >> city[i];
	dp.resize(n + 1);
	for(int i=1;i<=n;i++){
		ele_idx[city[i]].push_back(i);
	}

	for(int i=1;i<=n;i++){
		ll left = i, right = i ;
		vector<ll> selec(5001, 0);
		ll val = 0;
		ll tmp_ans = dp[i - 1];
		for(int j = i;j >= 1; j--){
			left = min(left, ele_idx[city[j]][0]);
			right = max(right, ele_idx[city[j]].back());
			if(selec[city[j]] == 0){val = val ^ city[j];selec[city[j]] = 1;}
			if(left >= j && right <= i){
				tmp_ans = val + dp[j - 1];
				dp[i] = max(dp[i], tmp_ans);
			}
		}
		dp[i] = max(dp[i - 1], dp[i]);
	}
	// for(int i=1;i<=n;i++)cout << dp[i] << " ";cout << endl; 
	cout <<  dp[n] << endl;
}