#include <bits/stdc++.h>
using namespace std ;

typedef long long int ll ;

int main(int argc, char const *argv[])
{
	int n;cin >> n;
	vector<ll> a(n+1);
	for (int i = 1; i <= n; ++i)cin >> a[i] ;
	int m ;cin>>m ;
	vector<ll> w(m+1),h(m+1) ;
	for (int i = 1; i <= m; ++i)cin >> w[i]>>h[i] ;

	ll curr = 0 ;

	for (int i = 1; i <= m; ++i)
	{
		ll b = max(curr, a[w[i]]) ;
		cout << b<<endl ;
		curr = b + h[i] ;
	}
	return 0;
}