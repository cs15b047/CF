#include <bits/stdc++.h>
using namespace std ;

typedef long long int ll ;

ll num_ways(ll n){
	ll k=2;
	ll ans=0;
	while(k*k*k <= n){
		ll q = n/(k*k*k) ;
		ans+=q;
		k++;
	}
	return ans;
}

int main()
{
	ll m;cin >>m;
	ll l = 8, r = 8*m, mid = (l+r)/2;
	ll flag = 0;
	while(l < r){
		mid = (l+r)/2;
		ll val = num_ways(mid);
		if(val == m){
			r = mid;
		}
		else if(val > m)r = mid - 1;
		else if(val < m)l = mid + 1;
	}
	if(num_ways(l)==m)
		cout << l<<endl;
	else cout << -1<<endl;
	return 0;
}