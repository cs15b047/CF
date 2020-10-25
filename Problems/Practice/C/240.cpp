#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll num_probs, Time, easy_time, hard_time;

ll add_extra(ll rem1, ll rem2, ll rem_time){
	ll ans = 0;
	ll easy = min(rem1, rem_time/easy_time);
	ans += easy;
	rem_time -= (easy * easy_time);
	ll hard = min(rem2, rem_time/hard_time);
	ans += hard;
	rem_time -= (hard * hard_time);
	return ans;
}

int main(){
	ll tests; cin >> tests;
	for(ll t = 0;t < tests;t++){
		cin >> num_probs >> Time >> easy_time >> hard_time;
		vector<int> hardness(num_probs);
		ll total_easy = 0, total_hard = 0;
		for(int i = 0;i < num_probs; i++){
			cin >> hardness[i];
			total_hard += hardness[i];
		}
		total_easy = num_probs - total_hard;

		vector<ll> mandatory_times(num_probs);
		for(int i = 0;i < num_probs; i++)cin >> mandatory_times[i];

		map<ll,pair<ll,ll>> prefix_num_prob_sum;
		for(int i = 0;i < num_probs;i++){
			if(!hardness[i])prefix_num_prob_sum[mandatory_times[i]].first++;
			else prefix_num_prob_sum[mandatory_times[i]].second++;
		}
		// take prefix sums
		vector<ll> times;
		int ii = 0;
		for(auto it:prefix_num_prob_sum)times.push_back(it.first);
		for(auto it = prefix_num_prob_sum.begin();it != prefix_num_prob_sum.end();it++){
			if(it != prefix_num_prob_sum.begin()){
				// prefix sum
				it->second = make_pair(prefix_num_prob_sum[times[ii - 1]].first + it->second.first, prefix_num_prob_sum[times[ii - 1]].second + it->second.second);
			}
			ii++;
		}
		// calculate 
		ii = 0;
		ll answer = 0;
		for(auto it = prefix_num_prob_sum.begin();it != prefix_num_prob_sum.end() && ii < times.size();it++,ii++){
			ll border_time = Time;
			if(ii < (ll)times.size() - 1){
				border_time = times[ii + 1] - 1;
			}
			// cout << border_time << " ";
			if(easy_time * it->second.first + hard_time * it->second.second <= border_time){
				ll remn_easy = total_easy - it->second.first, remn_hard = total_hard - it->second.second, remn_time = border_time - (easy_time * it->second.first + hard_time * it->second.second);
				answer = max(answer, it->second.first + it->second.second + add_extra(remn_easy, remn_hard, remn_time));
			}
		}
		answer = max(answer, add_extra(total_easy, total_hard, max((ll)0, times[0] - 1)));

		cout << answer << endl;
	}
}