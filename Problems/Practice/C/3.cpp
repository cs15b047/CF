#include <bits/stdc++.h>
using namespace std ;

typedef long long int ll ;

int main(int argc, char const *argv[])
{
	int n;cin>>n ;
	vector<ll> a(n) ;
	for(int i=0;i<n;i++)cin>>a[i] ;
	sort(a.begin(),a.end());
	ll ans=0;
	for(int i=0;i<n;i++){
		ans += abs(a[i] - (i+1)) ;
	}
	cout << ans <<endl ;
	return 0;
}