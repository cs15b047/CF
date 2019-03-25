#include <bits/stdc++.h>
using namespace std ;

typedef long long int ll ;

int main(int argc, char const *argv[])
{
	int n;cin>>n ;
	vector<ll>a(n);
	for(int i=0;i<n;i++)cin>>a[i];

	map<ll,ll> cnt ;
	for(int i=0;i<n;i++)cnt[a[i]]++;

	ll ans = 0;
	vector<vector<ll>> conseq ;
	for(auto it: cnt){
		if(cnt.find(it.first+1) == cnt.end() && cnt.find(it.first-1) == cnt.end()){
			ans += it.first * it.second ;
		}
		else if(cnt.find(it.first-1) == cnt.end()){
			vector<ll> temp ;
			conseq.push_back(temp);
			conseq.back().push_back(it.first*it.second) ;
		}
		else{
			conseq.back().push_back(it.first*it.second) ;
		}
	}

	for(int i=0;i<conseq.size();i++){
		ll s = conseq[i].size();
		vector<ll> curr = conseq[i] ;
		vector<ll>dp(s) ;
		dp[0] = curr[0] ;dp[1] = max(curr[1],curr[0]) ;
		for(int j=2;j<curr.size();j++){
			dp[j] = max(dp[j-1], dp[j-2] + curr[j]);
		}
		ans += dp[s-1] ;
		dp.clear();
	}
	cout << ans << endl ;
	return 0;
}