#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll t; cin >> t;
	for(int i = 0;i < t;i++){
		ll aa, bb, a, b; cin >> aa >> bb;
		a = min(aa, bb); b = max(aa, bb);
		if(a == b){
			cout << 0 << endl;
		} else{
			ll j = 1;
			for(;a + (j*(j + 1))/2 <= b; j++);
			// cout << j << endl;
			j--;
			if(a + (j*(j + 1))/2 == b)cout << j << endl;
			else{
				j++;
				// cout << j << endl;
				ll diff = (a + (j*(j + 1))/2 - b);
				if(diff % 2 == 0)cout << j << endl;
				else{
					if(j % 2 == 1){
						cout << j + 2 << endl;
					} else {
						cout << j + 1 << endl;
					}
				} 
			}
		}
	}
}