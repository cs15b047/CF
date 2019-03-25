#include <bits/stdc++.h>
using namespace std ;

typedef long long int ll ;

int main()
{
	ll n,k;cin >>n >>k ;
	set<ll>a;
	for(int i=0;i<n;i++){
		ll x;cin >> x ;
		a.insert(x);
	}

	if(k == 1){cout << n << endl ;exit(0);}	

	map<ll,set<ll>> multiples ;

	for(auto it:a){
		if(it%k==0 && a.find(it/k) != a.end()){
			ll num = it/k ;
			while(multiples.find(num) == multiples.end())num = num / k ;
			multiples[num].insert(it) ;
		}
		else{
			multiples[it].insert(it) ;
		}
	}
	ll ans=0;
	for(auto it: multiples){
		ans += (it.second.size() + 1)/2 ;
	}
	cout << ans << endl ;
}