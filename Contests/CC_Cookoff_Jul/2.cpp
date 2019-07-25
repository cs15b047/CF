#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll mod = 1000000007;

ll pwr(ll base, ll idx){
	if(idx == 0)return 1;
	ll tmp = pwr(base, idx / 2);
	ll ans1 = (tmp * tmp) % mod;
	if(idx % 2 == 0)return ans1;
	return (base * ans1) % mod;
}

ll gcd(ll a, ll b){
	if(b == 0)return a;
	return gcd(b, a%b);
}


int main(){
	ll t; cin >> t;
	for(int q = 0;q < t; q++){
		ll n, k; cin >> n >> k;
		ll sm = 0;vector<ll> a(n);for(int i=0;i<n;i++){cin >> a[i];sm +=a[i];}
		ll g = gcd(sm, n);
		sm /= g; n /= g;
		ll num = pwr(sm, k);
		ll denom = pwr(n, k);

		denom = pwr(denom, mod - 2);
		ll ans = (num * denom) % mod;
		cout << ans << endl;
	}	
}