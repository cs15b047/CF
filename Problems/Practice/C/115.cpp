//D. Almost Identity Permutations -- edu round 32
//Exact x are misplaced --> n -x correct & derangement(x)
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll fac(ll x){
	if(x == 0)return 1;
	return fac(x - 1)*x ;
}

ll derangement(ll j){
	if(j == 1)return 0;
	else{
		ll sgn = 1;
		ll prod = fac(j);
		ll ans = 0 ;
		for(ll i=2;i<=j;i++){
			ans += (prod *sgn)/fac(i);
			sgn = -sgn ;
		}
		return ans ;
	}
}

int main(){
	ll n,k;cin >> n >> k;
	ll prod = 1, ans = 0;
	for(ll j =1;j<=k;j++){
		prod = 1;
		for(ll i = 0;i <= j-1;i++){
			prod = prod * (n -i);
		}
		prod = (prod * derangement(j))/ fac(j) ;
		ans += prod ;
	}
	ans++; // all correct
	cout << ans << endl ;
}