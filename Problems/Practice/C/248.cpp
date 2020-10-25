#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;

typedef long long int ll;

typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n, t; cin >> n >> t;
	vector<ll> arr(n), suffix_sum(n, 0);
	for(int i =0; i < n;i++)cin >> arr[i];
	suffix_sum[n - 1] = arr[n - 1];for(int i = n - 2; i >= 0;i--)suffix_sum[i] = suffix_sum[i + 1] + arr[i];

	ordered_set ord_set;
	ord_set.insert(suffix_sum[n - 1]);
	
	ll answer = (suffix_sum[n - 1] < t);
	for(int i = n - 2; i >= 0;i--){
		if(suffix_sum[i] < t)answer++;
		ll ord = ord_set.order_of_key(suffix_sum[i] - t + 1);
		// cout << i << " " << ord << endl;
		answer += (ll)ord_set.size() - ord;
		ord_set.insert(suffix_sum[i]);
	}
	cout << answer << endl;
}