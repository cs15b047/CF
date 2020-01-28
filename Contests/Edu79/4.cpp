#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

ll gcd(ll a, ll b){
	if(b == 0)return a;
	else return gcd(b, a % b);
}

ll mod = 998244353;

ll pwr(ll base, ll idx){
	if(idx == 0)return (ll)1;
	else {
		ll tmp = pwr(base, idx / 2);
		if(idx % 2 == 0){
			return (tmp * tmp) % mod;
		} else{
			return (base *((tmp * tmp) % mod)) % mod;
		}
	}
}

ll inv(ll num){
	return pwr(num, mod - 2);
}

void print(pair<ll,ll> frac){
	cout << frac.first << " " << frac.second << endl;
}


int main(){
	ll n; scanf("%lld",&n);
	map<ll,ll> item_child_cnt;
	map<ll,vector<ll>> item_childs;
	ll numerator = 0, denom = n;
	ll sum_of_num_items = 0;
	vector<ll> bin_sizes(n);
	vector<vector<ll>> items(n);
	for(int i = 1; i <= n;i++){
		ll k; scanf("%lld",&k);
		bin_sizes[i - 1] = k;
		sum_of_num_items += k;
		for(int j = 1;j <= k ;j++){
			ll item; scanf("%lld",&item);
			item_child_cnt[item]++;
			item_childs[item].push_back(i - 1);
			items[i - 1].push_back(item);
		}
	}
	ll answer_repr = 0;
	for(auto it: item_childs){
		ll frac_repr = 0;
		for(auto child: it.second){
			ll frac2_repr = inv(bin_sizes[child]);
			frac_repr = (frac_repr + frac2_repr) % mod;
		}
		frac_repr = (frac_repr * item_child_cnt[it.first]) % mod;
		frac_repr = (frac_repr * inv((n*n)%mod)) % mod;
		answer_repr = (answer_repr + frac_repr) % mod;
	}
	printf("%lld\n", answer_repr);
}