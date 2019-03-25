#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll t; cin >> t;
	for(int i=0;i<t;i++){
		ll n; cin >> n ;
		if(n % 2 == 0)cout << n / 2 << endl ;
		else cout << (n-1)/2 << endl ;
	}	
}