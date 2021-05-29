#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll num_plots;
vector<ll> max_hts;

vector<vector<ll>> range_minimums;
map<pair<ll,ll>, pair<ll,ll>> correct_partition_cache;
vector<ll> assigned_ht;

void initialize(){
	correct_partition_cache.clear();
	scanf("%lld", &num_plots);
	assigned_ht.resize(num_plots);
	max_hts.resize(num_plots);
	for(int i = 0; i < num_plots; i++)scanf("%lld", &max_hts[i]);	
}

ll closest_power_to_length(ll length){
	ll closest_length_in_pow_of_2 = 1, closest_power = 0;
	while(2 * closest_length_in_pow_of_2 <= length){
		closest_length_in_pow_of_2 *= 2;
		closest_power++;
	}
	return closest_power;
}

void print_arr(){
	for(int i = 0; i < num_plots; i++){
		cout << "Minimums starting from : " << i << endl;
		for(auto it: range_minimums[i]) cout << it << " ";
		cout << endl;
	}
}

void print_partition_cache(){
	for(auto it: correct_partition_cache){
		cout << "[" << it.first.first << "," << it.first.second << "] --> " << "[" << it.second.first << "," << it.second.second << "]" << endl;
	}
}

void print_ht_assignment(){
	for(auto it: assigned_ht)printf("%lld ", it);
	printf("\n");
}

void preprocess_range_minimums(){
	ll pwr = closest_power_to_length(num_plots);
	// cout << "Closest pwr:" << pwr << endl;
	range_minimums.resize(num_plots, vector<ll>(pwr + 1, 1e9));
	for(ll i = 0;i <= pwr; i++){
		for(ll j = 0; j < num_plots; j++){
			// pwr -> 0, len of interval = 1 --> only jth element
			if(i == 0)range_minimums[j][0] = j;
			else {
				// divide into 2 half intervals: answer is min of both answers
				range_minimums[j][i] = range_minimums[j][i - 1];
				
				// check if second half is valid, then take min
				ll start_of_second_half = j + (ll)pow(2, i - 1);
				// cout << "Second half: " << start_of_second_half << endl;
				if(start_of_second_half < num_plots) {
					if(max_hts[range_minimums[j][i]] > max_hts[range_minimums[start_of_second_half][i - 1]]){
						range_minimums[j][i] = range_minimums[start_of_second_half][i - 1];
					}
				}
			}
		}
	}
}



ll get_range_min(ll left, ll right){
	// get power of 2 close to length of interval --> (right - left + 1)
	ll length = right - left + 1;
	ll closest_power = closest_power_to_length(length), closest_length_in_pow_of_2 = pow(2, closest_power);

	// layout the intervals: [left, left + closest_power_length - 1] and [right - closes_pwr_len + 1, right]
	ll minimum1 = range_minimums[left][closest_power], minimum2 = range_minimums[right - closest_length_in_pow_of_2 + 1][closest_power];
	
	if(max_hts[minimum1] < max_hts[minimum2])return minimum1;
	else return minimum2;
}


ll calc_ans(ll start_idx, ll end_idx){
	ll answer = 0, min_idx = -1;

	// base cases: invalid interval and only 1 element in interval
	if(start_idx > end_idx)answer = 0;
	else if(start_idx == end_idx)answer = max_hts[start_idx];
	else{
		min_idx = get_range_min(start_idx, end_idx);

		// assume that right part to min_idx is constant at that min ht and left is unrestricted
		ll ans_option1 = calc_ans(start_idx, min_idx - 1) + max_hts[min_idx] * (end_idx - min_idx + 1);

		// assume that left part to min_idx is constant at that min ht and right is unrestricted
		ll ans_option2 = calc_ans(min_idx + 1, end_idx) + max_hts[min_idx] * (min_idx - start_idx + 1);

		answer = max(ans_option1, ans_option2);

		// (1--> left, 2--> right) is to be given free hand
		if(ans_option1 > ans_option2)correct_partition_cache[make_pair(start_idx, end_idx)] = make_pair(min_idx, 1);
		else correct_partition_cache[make_pair(start_idx, end_idx)] = make_pair(min_idx, 2);
	}
	// cout << start_idx << " " << end_idx << " " << min_idx << " " << answer << endl;
	return answer;
}

void make_ht_assignments(ll start_idx, ll end_idx){
	if(start_idx >  end_idx) return;
	if(start_idx == end_idx) assigned_ht[start_idx] = max_hts[start_idx];

	pair<ll,ll> partition = correct_partition_cache[make_pair(start_idx, end_idx)];
	// give left a free hand, restrict all right to minimum
	if(partition.second == 1){
		for(int i = partition.first; i <= end_idx; i++) assigned_ht[i] = max_hts[partition.first];
		make_ht_assignments(start_idx, partition.first - 1);
	} else if(partition.second == 2) { // give right a free hand, restrict all left to minimum
		for(int i = start_idx; i <= partition.first; i++) assigned_ht[i] = max_hts[partition.first];
		make_ht_assignments(partition.first + 1, end_idx);
	}
}




int main(){
	initialize();
	preprocess_range_minimums();
	// print_arr();
	ll answer = calc_ans(0, num_plots - 1);
	// print_partition_cache();
	make_ht_assignments(0, num_plots - 1);
	print_ht_assignment();
	// printf("%lld\n", answer);
}