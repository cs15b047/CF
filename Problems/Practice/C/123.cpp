// C. Geometric Progression #Pi - 2
//1. Find 3 len GP ending in i
// for that dp[i] = # of numbers from 1 to i-1 equal to a[i]/k
// take prefix sum of such dp for all numbers. ans[i] = prefix sum of i - 1 for number a[i]/k
// total answer = sum over i(ans[i])
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll n, k; cin >> n >> k ;
	vector<ll> a(n+1);for(ll i=1;i<=n;i++)cin >> a[i] ;
	vector<ll>dp(n+1), ans(n+1);
	map<ll,ll> prefix_counts;

	for(ll i=1;i<=n;i++){
		if(a[i] % k == 0)dp[i] = prefix_counts[a[i]/k] ;
		prefix_counts[a[i]]++;
	}
	map<ll,ll> prefix_sum;
	for(ll i=1;i<=n;i++){
		if(i >= 3){
			if(a[i] % k*k == 0)ans[i] = prefix_sum[a[i]/k];
		}
		prefix_sum[a[i]] += dp[i];
	}
	ll answer = 0 ;
	for(int i=1;i<=n;i++){
		answer += ans[i];
	}
	cout << answer << endl;
}