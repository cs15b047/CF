#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll t; scanf("%lld",&t);
	for(int q = 0;q <t;q++){
		ll n;scanf("%lld",&n);
		vector<ll> a(n);for(int i=0;i<n;i++)scanf("%lld",&a[i]);
		sort(a.begin(), a.end(), greater<ll>());
		ll ans = min(a[1] - 1, n - 2);
		printf("%lld\n",ans);
	}
}