#include <bits/stdc++.h>
using namespace std ;

typedef long long int ll ;

int main(int argc, char const *argv[])
{
	ll n,m;cin >>n >>m ;
	vector<ll> v(m) ; 
	for (int i = 0; i < m; ++i)cin >> v[i] ;	
	ll ans = 0; 
	for (int i = 0; i < m; ++i)
	{
		ll d ;
		if (i > 0)
		{
			if (v[i] >= v[i-1])d = v[i]-v[i-1] ;
			else d = n + (v[i] - v[i-1]) ;			
		}
		else{
			d = v[0] - 1 ;
		}
		ans += d ;
		
	}
	cout << ans <<endl ;

	return 0;
}