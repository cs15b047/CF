#include <bits/stdc++.h>
using namespace std ;

typedef long long int ll ;

int main()
{
	ll n,k;scanf("%lld%lld",&n,&k);
	vector<ll> a(n+1);for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	vector<ll>pref(n+1);pref[0] =0;for(int i=1;i<=n;i++)pref[i] = pref[i-1]+a[i];

	map<ll,ll>cnt;cnt[0]++;
	ll ans = 0;
	ll mxm = 1e15;
	set<ll> k_pwrs;
	if(k == 1)k_pwrs.insert(1);
	else if(k ==-1){
		k_pwrs.insert(-1);
		k_pwrs.insert(1);
	}
	else{
		ll pwr = 0;
		while(abs((ll)pow(k,pwr)) <= mxm){
			k_pwrs.insert((ll)pow(k,pwr));
			pwr++;
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		for(auto it:k_pwrs){
			ll reqd = pref[i] - it ;
			if(cnt.find(reqd) != cnt.end())ans+=cnt[reqd];
		}
		cnt[pref[i]]++;
	}
	cout << ans << endl ;
}