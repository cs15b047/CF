#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll t; cin >> t;
	for(int i = 0;i < t; i++){
		ll r, g, b; cin >> r >> g >> b;
		if(2*max(max(r,g), b) > (r + g + b) + 1){
			cout << "No" << endl;
		} else{
			cout << "Yes" << endl;
		}
	}
}