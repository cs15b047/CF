#include <bits/stdc++.h>
using namespace std ;

typedef long long int ll ;

int main(int argc, char const *argv[])
{
	int n;cin >>n ;
	vector<ll> h(n) ;
	for (int i = 0; i < n; ++i)
	{
		cin >> h[i] ;
	}
	ll ans = 0 ;
	for (int i = 0; i < n; ++i)
	{
		ans = max(ans, h[i]) ;
	}
	cout << ans <<endl ;
	return 0;
}