#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll mod = 998244353;

int main(){
	ll t; cin >> t;
	for(int x = 0;x < t;x++){
		ll n, m, q; cin >> n >> m >> q;
		vector<ll> arr(n);for(int i = 0;i < n;i++)cin >> arr[i];
		if(q == 1){
			ll pos, val; cin >> pos >> val;
			arr[pos - 1] = val;
			vector<ll> pr_arr(n + 1, 0);pr_arr[0] = 0;
			for(int i = 1;i <= n;i++)pr_arr[i] = pr_arr[i - 1] + arr[i - 1];
			vector<ll> partials(m, 0);
			for(int i = 0;i < m;i++)partials[i] = pr_arr[n - m + 1 + i] - pr_arr[i];
			ll ans = 0;
			for(int i = 0;i < m;i++)ans = (ans + (partials[i] * partials[i]) % mod) % mod;
			cout << ans << endl;
		} else {
			for(int i = 0;i < q;i++){
				ll pos, val; cin >> pos >> val;
			}
		}
	}
}