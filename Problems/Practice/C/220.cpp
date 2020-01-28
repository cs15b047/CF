#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll num_nodes, window_sz; cin >> num_nodes >> window_sz;
	vector<ll> parent(num_nodes + 1), dp(num_nodes + 1, 0);
	for(int i = 1;i <= num_nodes;i++)cin >> parent[i];

	dp[0] = 0;

	for(ll i = 1;i <= num_nodes; i++){
		ll left = max((ll)1, i - window_sz), right = min(num_nodes, i + window_sz);
		if(parent[i] == 0){
			dp[i] = right - left + 1;
		} else{
			ll par_left = max((ll)1, parent[i] - window_sz), par_right = min(num_nodes, parent[i] + window_sz);
			
			// subtract overlap of parent and node
			if(par_right < left){
				dp[i] = dp[parent[i]] + (right - left + 1);
			} else{
				dp[i] = dp[parent[i]] + (right - par_right);
			}
		}
		cout << dp[i] << " ";
	}
	cout << endl;


}