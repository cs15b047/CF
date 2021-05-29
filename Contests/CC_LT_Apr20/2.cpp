#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ll t; cin >> t;
	for(int xx = 0;xx < t;xx++){
		ll n, q; cin >> n >> q;
		vector<ll> x(n), y(n);
		for(int i = 0;i < n;i++){
			ll ptx, pty;
			cin >> x[i] >> y[i];
		}
		ll left, right;
		cin >> left >> right;
		ll d = right - left;
		vector<ll> x_min_y, x_plus_y;
		for(int i = 0;i < n;i++){
			if(y[i] <= d/2){
				x_min_y.push_back(x[i] - y[i]);
				x_plus_y.push_back(x[i] + y[i]);
			}
		}
		// for(auto it:x_min_y)cout << it << " ";cout << endl;
		// for(auto it:x_plus_y)cout << it << " ";cout << endl;
		ll sz = x_plus_y.size();
		// cout << sz << endl;
		sort(x_min_y.begin(), x_min_y.end());
		sort(x_plus_y.begin(), x_plus_y.end());

		for(int i = 0;i < q;i++){
			if(i > 0)cin >> left >> right;
			ll ans = 0;
			ll idx1 = lower_bound(x_min_y.begin(), x_min_y.end(), left) - x_min_y.begin();
			ll idx2 = upper_bound(x_plus_y.begin(), x_plus_y.end(), right) - x_plus_y.begin();
			// cout << idx1 << " " << idx2 << endl;
			ans = (sz - idx1) + idx2 - sz;
			cout << ans << " ";
		}
		cout << endl;
	}
}