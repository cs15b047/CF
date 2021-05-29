#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll tests; cin >> tests;
	for(int t = 0 ;t < tests;t++){
		ll d, m; cin >> d >> m;
		ll N = (ll)(log2(d)) + 1;
		vector<vector<ll>> dp(N + 1, vector<ll>(N + 1, 0));

		for(int len = 1;len <= N;len++){
			for(int max_pwr = len;max_pwr <= N;max_pwr++){
				ll multiplier;
				if(max_pwr == N){
					multiplier = (d - (ll)pow(2, max_pwr - 1) + 1) % m;
				} else{
					multiplier = (ll)pow(2, max_pwr - 1) % m;
				}
				if(len == 1){
					dp[max_pwr][len] = multiplier % m;
				}else if(len == max_pwr){
					dp[max_pwr][len] = (multiplier * dp[max_pwr - 1][len - 1]) % m;
				} else{
					dp[max_pwr][len] = 0;
					for(int pwr = len - 1;pwr <= max_pwr - 1;pwr++){
						dp[max_pwr][len] = (dp[max_pwr][len] + dp[pwr][len - 1]) % m;
					}
					dp[max_pwr][len] = (dp[max_pwr][len] * multiplier) % m ;
				}
			}
		}
		ll answer = 0;
		for(int len = 1;len <= N;len++){
			for(int max_pwr = len;max_pwr <= N;max_pwr++){
				answer = (answer + dp[max_pwr][len]) % m;
			}
		}
		cout << answer << endl;
	}

}