#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll gcd(ll a, ll b){
	if(b == 0)return a;
	return gcd(b, a % b);
}

int main(){
	ll q; scanf("%lld",&q);
	for(int w = 0;w < q; w++){
		ll n; scanf("%lld",&n);
		vector<ll> prices(n);for(int i =0;i<n;i++){scanf("%lld",&prices[i]);prices[i] = prices[i]/100;}
		ll x, a, y, b, k; scanf("%lld%lld%lld%lld%lld",&x,&a,&y,&b,&k);

		sort(prices.begin(), prices.end(), greater<ll>());

		vector<ll> prefix_prices(n + 1, 0);
		prefix_prices[0] = 0;
		for(int i =1;i<=n;i++)prefix_prices[i] = prefix_prices[i - 1] + prices[i - 1];

		ll lcm = (a * b) / gcd(a, b);
		bool done = false;
		ll answer = -1;
		for(ll pos = 1;pos <= n;pos++){
			ll n_first = pos / a, n_second = pos / b, n_common = pos / lcm;
			n_first -= n_common;
			n_second -= n_common;

			ll mult1, mult2;
			ll ptr1 = n_common, ptr2, ptr3 = n_common + n_first + n_second;
			if(x >= y){
				ptr2 = ptr1 + n_first;
				mult1 = x;
				mult2 = y;
			} else{
				ptr2 = ptr1 + n_second;
				mult1 = y;
				mult2 = x;
			}
			// cout << ptr1 << " " << ptr2 << " " << ptr3 << endl;
			ll mxm_val_possible = 0;
			if(ptr1 != 0){
				mxm_val_possible += prefix_prices[ptr1] * (x + y);	
			}
			if(ptr2 != ptr1){
				mxm_val_possible += (prefix_prices[ptr2] - prefix_prices[ptr1]) * mult1;
			}
			if(ptr3 != ptr2){
				mxm_val_possible += (prefix_prices[ptr3] - prefix_prices[ptr2]) * mult2;
			}
			// cout << mxm_val_possible << endl;
			if(mxm_val_possible >= k){
				done = true;
				answer = pos;
				break;
			}
		}
		cout << answer << endl;
	}
}