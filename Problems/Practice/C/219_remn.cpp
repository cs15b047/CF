// Winter is coming
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<ll> temp;

int main(){
	ll num_days, allowed_days; cin >> num_days >> allowed_days;
	temp.resize(num_days);for(int i = 0;i < num_days;i++)cin >> temp[i];

	ll reqd_days = 0;
	for(int i = 0;i < num_days;i++)reqd_days += (temp[i] < 0);
	ll answer = 0;
	if(reqd_days > allowed_days){
		answer = -1;
	} else{
		// non -ve intervals
		vector<pair<ll,ll>> non_reqd_intervals;
		
		ll curr = 0;
		while(curr < num_days){
			while(curr < num_days && temp[curr] < 0)curr++;
			if(curr >= num_days)break;

			ll strt = curr, end = curr;
			while(curr < num_days && temp[curr] >= 0){
				end++;
				curr++;
			}
			end--;
			non_reqd_intervals.push_back(make_pair(strt, end));
		}
		for(auto it: non_reqd_intervals)cout << it.first << " " << it.second << endl;
		// all negative temp
		if(non_reqd_intervals.empty()){
			answer = 1;
		} else if(non_reqd_intervals.size() == 1){ // no negatives
			answer = 0;
		} else{
			if(non_reqd_intervals[0].first == 0){
				non_reqd_intervals.erase(non_reqd_intervals.begin());
			}

			vector<ll> lengths;lengths.clear();
			for(auto it: non_reqd_intervals){
				lengths.push_back(it.second - it.first + 1);
			}
			sort(lengths.begin(), lengths.end());
			for(auto it: lengths)cout << it << " ";cout << endl;
			ll extra = allowed_days - reqd_days;
			
			vector<ll> prefix_length_sum(lengths.size(), 0);
			prefix_length_sum[0] = lengths[0];
			for(int i = 1;i < lengths.size();i++)
				prefix_length_sum[i] = prefix_length_sum[i - 1] + lengths[i];
			for(auto it: prefix_length_sum)cout << it << " ";cout << endl;
			
			ll idx = upper_bound(prefix_length_sum.begin(), prefix_length_sum.end(), extra) - prefix_length_sum.begin();
			answer = 1 + 2*((ll)non_reqd_intervals.size() - idx);
			if(temp.back() >= 0)answer--;
		}
	}
	cout << answer << endl;
}