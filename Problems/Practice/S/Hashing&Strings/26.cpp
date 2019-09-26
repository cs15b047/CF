// Construct graph and understand graph structure to reduce computations
#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll;

int main(){
	ll n; cin >> n;
	vector<string> str(n);
	for(int i=0;i<n;i++)cin >> str[i];
	map<vector<bool>, ll> counts;
	for(int i=0;i<n;i++){
		vector<bool> arr(26, 0);
		for(int j = 0;j < str[i].length();j++){
			ll idx = str[i][j] - 'a';
			arr[idx] = !arr[idx];
		}
		counts[arr]++;
		// cout << "stuck" << endl;
	}
	ll ans = 0;
	for(auto it: counts){
		ans += it.second*(it.second - 1);
		vector<bool> arr = it.first;
		ll cnt = it.second;
		for(int i=0;i<26;i++){
			arr[i] = !arr[i];
			if(counts.find(arr) != counts.end())ans += counts[arr] * cnt;
			arr[i] = !arr[i];
		}
		// cout << "stuck2" << endl;
	}
	ans = ans / 2;
	cout << ans << endl;
}