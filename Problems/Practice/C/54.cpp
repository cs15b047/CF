#include <bits/stdc++.h>
using namespace std ;

typedef long long int ll ;
ll mod = 1e9+7;

ll pwr(ll l){
	if(l==0)return 1;
	ll tmp = pwr(l/2);
	if(l % 2 == 0)
		return (tmp *tmp) % mod ;	
	else
		return (2*((tmp*tmp)%mod)) %mod ;	
}


int main(){
	ll n;cin>>n;
	vector<ll>x(n);
	for(int i=0;i<n;i++)scanf("%lld",&x[i]);
	sort(x.begin(),x.end());
	
	vector<ll>pref(n);
	pref[0] = x[0];
	for(int i=1;i<n;i++)pref[i] = (pref[i-1] + x[i]) ;

	ll ans = 0 ;
	for(int l=0;l<=n-2;l++){
		ans = ans + ((((pref[n-1] - pref[l]) - pref[n-l-2] + mod)% mod) * pwr(l)) % mod ;
		ans = ans % mod ;
	}
	cout << ans << endl ;

}