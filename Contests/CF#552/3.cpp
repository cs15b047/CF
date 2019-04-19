#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;
ll mod = 1e9 + 7;

ll fn(ll r){
	vector<pair<ll,ll>> l_int,r_int;
	ll i = 1, pwr = 0,l=1,rr=1;
	while(i <= r){
		ll mnm = min((ll)pow(2, pwr), r + 1 - i);
		if(pwr % 2 == 1){r_int.push_back(make_pair(rr, rr + mnm - 1));rr+=mnm;}
		else {l_int.push_back(make_pair(l,l + mnm - 1));l+=mnm;}
		i += mnm;pwr++;
	}

	ll answ = 0;
	for(auto it:r_int){
		answ = answ + (((it.first + it.second) % mod) * ((it.second - it.first + 1) % mod)) % mod;
		answ = answ % mod;
	}
	for(auto it:l_int){
		answ = answ + (((it.first + it.second - 1) % mod) * ((it.second - it.first + 1) % mod)) % mod;
		answ = answ % mod;
	}
	return answ;
}

int main(){
	ll l,r; cin >> l >> r;
	ll a1 = fn(r), a2 = fn(l - 1);
	cout << (a1 - a2 + mod) % mod << endl;
}