#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll tests; cin >> tests;
	for(int t = 0;t < tests;t++){
		ll n; cin >> n;
		vector<ll> arr(n + 1); for(int i = 1;i <= n;i++)cin >> arr[i];

		set<ll> ans_side1, ans_side2, prefix_set, suffix_set;

		ll prefix_mx = -1, suffix_mx = -1;
		for(int i = 1;i <= n;i++){
			if(prefix_set.find(arr[i]) == prefix_set.end()){
				prefix_set.insert(arr[i]);
				prefix_mx = max(prefix_mx, arr[i]);
				if(prefix_mx == i){
					ans_side1.insert(i);
				}
			} else{
				break;
			}
		}

		for(int i = 1;i <= n;i++){
			if(suffix_set.find(arr[n + 1 - i]) == suffix_set.end()){
				suffix_set.insert(arr[n + 1 - i]);
				suffix_mx = max(suffix_mx, arr[n + 1 - i]);
				if(suffix_mx == i){
					ans_side2.insert(n + 1 - i);
				}
			} else{
				break;
			}
		}
		ll cnt = 0;
		vector<pair<ll,ll>> answer;
		for(auto it: ans_side1){
			if(ans_side2.find(it + 1) != ans_side2.end()){
				answer.push_back(make_pair(it, n - it));
				cnt++;
			}
		}
		cout << cnt << endl;
		for(auto it: answer)cout << it.first << " " << it.second << endl;
	}

}