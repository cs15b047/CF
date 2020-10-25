#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll n, m; scanf("%lld%lld",&n, &m);
	vector<ll> arr(n);for(int i = 0;i < n;i++)scanf("%lld",&arr[i]);

	map<ll, vector<ll>> element_locns;
	for(int i = 0;i < n; i++)element_locns[arr[i]].push_back(i);

	vector<ll> to_be_removed;
	for(auto it: element_locns){
		if(it.first > it.second.size()){
			to_be_removed.push_back(it.first);
		}
	}
	for(auto it: to_be_removed){
		element_locns.erase(it);
	}

	map<ll, vector<ll>> locations;
	for(auto it: element_locns){
		vector<ll> arr(n + 1, 0);
		for(auto it2: it.second){
			arr[it2 + 1] = 1;
		}
		for(int i = 1;i <= n;i++)arr[i] += arr[i - 1];
		locations[it.first] = arr;
	}

	for(int i = 0;i < m; i++){
		ll left, right; scanf("%lld%lld",&left, &right);
		ll ans = 0;
		for(auto it: element_locns){
			if(locations[it.first][right] - locations[it.first][left - 1] == it.first)ans++;
		}
		printf("%lld\n",ans);
	}
}