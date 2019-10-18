#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll q; scanf("%lld",&q);
	for(int w =0;w <q;w++){
		ll n; scanf("%lld",&n);
		vector<ll> arr(n);for(int i = 0;i < n;i++)scanf("%lld",&arr[i]);
		map<ll, set<ll>> locns;for(int i = 0;i < n;i++)locns[arr[i]].insert(i);

		set<ll> uniq_ele; for(int i = 0;i < n;i++)uniq_ele.insert(arr[i]);
		vector<ll> ele;for(auto it:uniq_ele)ele.push_back(it);
		ll sz = ele.size();
		ll mxm = (ll)uniq_ele.size() - 1;
		vector<ll> dp(sz, 0);dp[0] = 1;
		for(int i =1;i < sz;i++){
			ll first_loc = *locns[ele[i]].begin(), prev_last = *locns[ele[i - 1]].rbegin();
			if(prev_last < first_loc){
				dp[i] = dp[i - 1] + 1;
			} else{
				dp[i] = 1;
			}
		}
		ll mxm_len = 1;for(int i =0;i < sz;i++)mxm_len = max(mxm_len, dp[i]);
		cout << sz - mxm_len << endl;
	}
}