#include <bits/stdc++.h>
using namespace std ;

typedef long long int ll ;
ll mod = 1e9+9;

ll pwr(ll x){
	if(x == 0)return 1;
	else if(x % 2 == 0){
		ll tmp = pwr(x/2) ;
		return ((tmp % mod) * (tmp % mod)) ;
	}
	else{
		ll tmp = pwr(x/2) ;
		return ((tmp % mod) * (tmp % mod) * 2) ;
	}
}

int main()
{
	ll n,m,k;cin>>n>>m>>k;
	ll free = n - m;
	if((m - (free+1)*(k-1)) <= 0)cout << m<< endl ;
	else{
		m = m - (free*(k-1));
		ll q = m/k, r= m%k;
		ll ans = 0,p1,p2;
		p1 = (((2*k) % mod) * ((pwr(q) + mod - 1) % mod)) % mod ;
		p2 = r ;
		ans = (((p1+p2) % mod) + ((free*(k-1)) % mod)) % mod ;
		cout << ans << endl;
	}

	return 0;
}