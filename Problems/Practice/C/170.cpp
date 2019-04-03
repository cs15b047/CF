#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

ll bin_search(ll n, ll mod3){
	// cout << mod3 << endl;
	ll l = (mod3 == 0),r = (ll)sqrt(n),m;
	ll x = 3*l + mod3;
	if((x*(3*x + 1))/2 > n)return -1;
	while(l < r){
		m = (ll)ceil((float)(l + r)/(float)2) ;

		x = 3*m + mod3 ;
		ll expr = (x*(3*x + 1))/2 ;
		
		if(expr > n){
			r = m - 1;
		}
		else{
			l = m;
		}
	}
	// cout << l << endl;
	return l;
}


int main(){
	ll n; cin >> n;
	ll mod3;
	if(n % 3 == 0)mod3 = 0;
	else if(n%3==1)mod3 = 2;
	else mod3 = 1;

	ll strt = (mod3==0);

	ll idx = bin_search(n, mod3);
	if(idx == -1){
		cout << 0 << endl ;
	}
	else{
		cout << (idx - strt + 1) << endl ;
	}
}