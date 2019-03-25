#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll n; cin >> n ;

	bool not_prime[100001]={};

	ll sq = (ll)sqrt(n);
	set<ll> div, sums;div.clear();sums.clear();
	for(ll i = 2; i<= sq; i++){
		if(n % i == 0){
			div.insert(i);
			div.insert(n / i);
		}
	}
	div.insert(1);

	for(auto it:div){
		ll ans = ((n + 2) * ((n / it) + 1)) / 2   - (n + 1);
		sums.insert(ans);
	}
	sums.insert(1);
	for(auto it: sums){
		cout << it << " ";
	}
	cout << endl ;
}