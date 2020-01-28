#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll t; cin >> t;
	for(int q = 0;q < t;q++){
		ll n, s, k; cin >> n >> s >> k;
		vector<ll> a(k);for(int i = 0;i<k;i++)cin >> a[i];
		set<ll>closed;for(auto it:a)closed.insert(it);
		ll d1 = 1e10,d2 =1e10;
		for(ll i = s;i <= n;i++){
			if(closed.find(i) == closed.end()){
				d1 = i - s;
				break;
			}
		}
		for(ll i = s;i >= 1;i--){
			if(closed.find(i) == closed.end()){
				d2 = s - i;
				break;
			}
		}
		// cout << d1 << " " << d2 << endl;
		cout << min(d1, d2) << endl;
	}
}