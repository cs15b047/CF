#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll mod = 998244353;

int main(){
	ll n; cin >> n;
	vector<ll> fac(n + 1), perm(n + 1);
	fac[0] = 1;

	for(ll i = 1;i <=n ;i++){
		fac[i] = (fac[i - 1] * i) % mod ;
	}
	perm[0] = 1 ;
	for(ll i = 1;i < n; i++){
		perm[i] = (perm[i - 1] * (n - i + 1)) % mod ;
	}

	ll ans = 0;
	for(ll i = 0;i < n ;i++){
		ans = ans + (fac[n] - perm[i] + mod) % mod ;
	}
	cout << (ans + 1) % mod << endl ;
}