#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main()
{
	ll n;cin>>n;
	ll ans =2;
	for(int i=0;i<n;i++){
		ll x,y;scanf("%lld%lld",&x,&y);
		ans = max(ans, x+y);
	}
	cout << ans << endl ;
	
	return 0;
}