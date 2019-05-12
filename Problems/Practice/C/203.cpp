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