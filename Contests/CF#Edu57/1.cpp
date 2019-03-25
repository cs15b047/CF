#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll t; cin >> t;
	for(int i=0;i<t;i++){
		ll l,r; cin >> l >> r;
		if(r % 2 != 0)r--;
		cout << r/2 << " " << r << endl ;
	}
}