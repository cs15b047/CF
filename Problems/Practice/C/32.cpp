#include <bits/stdc++.h>
using namespace std ;

typedef long long int ll ;

int main()
{
	ll n,d;cin >>n>>d ;
	vector<ll>pt(n);
	for(int i=0;i<n;i++)cin >> pt[i] ;
	ll ans=  0;
	for(ll i=0;i<n-2;i++)	
	{
		ll j = upper_bound(pt.begin(),pt.end(), pt[i] + d) - pt.begin() ;		
		j--;
		if(j-i>=2){
			ans += ((j-i)*(j-i-1))/2 ;
		}
	}
	cout << ans << endl ;

	return 0;
}