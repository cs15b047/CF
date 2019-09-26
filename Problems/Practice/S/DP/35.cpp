#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

ll dp[1000001] = {}, pre[1000001] = {};

int main(){
	ll v; cin >> v;
	vector<ll> a(10);for(int i = 1;i <= 9;i++)cin >> a[i];
	for(int i = 1; i <= v; i++){
		for(int j = 9; j >= 1; j--){
			if(i >= a[j] && dp[i - a[j]] + 1 > dp[i]){
				// cout << i << " " << j << " " << a[j] << endl;
				pre[i] = j;
				dp[i] = dp[i - a[j]] + 1;
			}
		}
		// cout << dp[i] << endl;
		// cout << pre[i] << endl;
	}
	if(dp[v] == 0){
		cout << -1 << endl;
	}
	else{
		ll curr = v;
		while(curr >= 0 && pre[curr] != 0){
			cout << pre[curr];
			curr -= a[pre[curr]];
		}
	}
}