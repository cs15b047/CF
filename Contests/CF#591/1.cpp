#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll q; cin >> q;
	for(int i = 0;i < q;i++){
		ll n; cin >> n;
		if(n <= 4){
			cout << 4 - n << endl;
		} else{
			cout << n % 2 << endl;
		}
	}
}