#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll tests;
ll soln_array_size;
vector<ll> merged_array;

vector<ll> fragment_lengths;
vector<vector<ll>> dp;
bool valid;

void print(vector<ll>& v){
	for(auto ele: v) cout << ele << " ";
	cout << endl;
}

void init(){
	merged_array.clear();
	fragment_lengths.clear();
	dp.clear();
}

void take_input(){
	scanf("%lld",&soln_array_size);
	merged_array.resize(2 * soln_array_size);
	for(int i = 0;i < 2 * soln_array_size;i++){
		scanf("%lld",&merged_array[i]);
	}
}

void fragment_array(){
	while(!merged_array.empty()){
		ll sz = merged_array.size();

		// Find max element in remn array, and its index
		auto it = max_element(merged_array.begin(), merged_array.end());
		ll idx = it - merged_array.begin();

		ll fragment_length = (sz - idx);
		fragment_lengths.push_back(fragment_length);

		// reduce array
		merged_array.erase(it, merged_array.end());

		// print(merged_array);
		// cout << "Fragment length: " << fragment_length << endl;
	}
}

bool validate_fragments(){
	// given array of elements summing to 2n, find if there is subset that sums to half(n)
	
	ll target_sum = soln_array_size;
	ll num_fragments = fragment_lengths.size();
	dp.resize(soln_array_size + 1, vector<ll>(num_fragments + 1, false));
	dp[0][0] = true;

	for(int j = 1;j <= num_fragments; j++){
		for(int i = 1;i <= target_sum;i++){
			
			dp[i][j] = dp[i][j - 1];

			if(i >= fragment_lengths[j - 1]) dp[i][j] = dp[i][j] || dp[i - fragment_lengths[j - 1]][j - 1];
		}
	}

	// cout << "DP Matrix:" << endl;
	// for(int i = 0;i <= target_sum;i++){
	// 	print(dp[i]);
	// }

	return dp[target_sum][num_fragments];

}


int main(){
	scanf("%lld",&tests);
	for(int t = 0;t < tests;t++){
		init();
		take_input();
		fragment_array();
		valid = validate_fragments();
		if(valid)printf("YES\n");
		else printf("NO\n");
	}
}