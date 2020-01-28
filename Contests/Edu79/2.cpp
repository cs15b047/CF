#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll t; scanf("%lld",&t);
	for(int q = 0;q < t; q++){
		ll n, s; scanf("%lld%lld",&n, &s);
		vector<ll> times(n), prefix_sum_times(n);for(int j = 0;j < n; j++)scanf("%lld",&times[j]);
		prefix_sum_times[0] = times[0];
		for(int j = 1;j < n; j++)prefix_sum_times[j] = prefix_sum_times[j - 1] + times[j];

		ll answer;
		if(prefix_sum_times.back() <= s)answer = 0;
		else{
			ll no_skip_ans;
			no_skip_ans = upper_bound(prefix_sum_times.begin(), prefix_sum_times.end(), s) - prefix_sum_times.begin();
			ll skip_ans = no_skip_ans;
			ll idx = -1;
			for(int i = 0; i <= max(no_skip_ans, n - 1); i++){
				ll tmp_ans = upper_bound(prefix_sum_times.begin(), prefix_sum_times.end(), s + times[i]) - prefix_sum_times.begin();
				tmp_ans = tmp_ans - 1;
				if(skip_ans < tmp_ans){
					idx = i;
					skip_ans = tmp_ans;
				}
			}
			answer = idx + 1;
		}
		printf("%lld\n", answer);
	}
}