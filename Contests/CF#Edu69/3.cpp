#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll n, k; cin >> n >> k;
	vector<ll> a(n); for(int i=0;i<n;i++)cin >> a[i];
	if(n == 1)cout << 0 << endl;
	else {
		vector<ll> diff(n - 1);for(int i=0;i < n - 1;i++)diff[i] = a[i + 1] - a[i];
		sort(diff.begin(), diff.end(), greater<ll>());
		ll sz = diff.size();
		ll ans = 0;
		for(int i = k - 1;i < sz;i++)ans += diff[i];
		cout << ans << endl;
	}
}