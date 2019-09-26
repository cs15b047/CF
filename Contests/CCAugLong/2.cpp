#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll t; cin >> t;
	for(int q = 0;q < t;q++){
		ll n; cin >> n; vector<ll> arr(n);for(int i=0;i<n;i++)cin >> arr[i];
		ll curr = 0;
		map<ll, vector<ll>> prefix_xor;prefix_xor[0].push_back(-1);for(int i=0;i<n;i++){curr = curr ^ arr[i]; prefix_xor[curr].push_back(i);}
		ll ans = 0;
		for(auto it: prefix_xor){
			vector<ll> locns = it.second;
			// cout << it.first << endl;
			// for(auto it2: locns)cout << it2  << " ";cout << endl;
			ll sz = locns.size();
			for(int i = 0;i < sz -1; i++){
				ll len = locns[i + 1] - locns[i];
				ll vtx = i + 1;
				ans += vtx * (sz - vtx) * (len - 1);
			}
		}
		cout << ans << endl;
	}
}