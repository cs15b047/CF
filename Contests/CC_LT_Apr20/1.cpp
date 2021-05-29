#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll mod = 998244353;
ll pwr(ll b, ll e){
	if(e == 0)return 1;
	ll tmp = pwr(b, e/2);
	tmp = (tmp * tmp) % mod;
	if(e % 2 == 1)return (tmp * b) % mod;
	return tmp;
}

int main(){
	ll t; cin >> t;
	for(int xx = 0;xx < t;xx++){
		ll n; cin >> n;
		vector<ll> arr(n);for(int i = 0;i < n;i++)cin >> arr[i];
		sort(arr.begin(), arr.end());
		ll num = 1;
		vector<ll> cnts(n + 1, 0), pr_cnts(n + 1, 0);
		for(auto it: arr){
			if(it < num)cnts[it]++;
			else if(it == num){
				cnts[it]++;
				num++;
			} else break;
		}
		for(int i = 1;i < num;i++){
			pr_cnts[i] = pr_cnts[i - 1] + cnts[i];
		}

		ll ans = 0;
		ll prod = 1;
		for(int i = 1;i <= num - 1;i++){
			ll tmp = (((prod * pwr(2, n - pr_cnts[i])) % mod)* i) % mod;
			ans = (ans + tmp) % mod;
			prod = (prod * (pwr(2, cnts[i]) - 1)) % mod;
		}
		ans = (ans  + (((prod * pwr(2, n - pr_cnts[num - 1]))% mod) * num) % mod) % mod;
		cout << ans << endl;
	}
}