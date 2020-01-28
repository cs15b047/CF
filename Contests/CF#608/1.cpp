#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
	ll a,b,c,d,e,f; cin >> a >> b >> c >> d >> e >> f;
	ll ans;
	if(e < f){
		ll x = min(b,c);x = min(x, d);
		ans = x * f + min(a, d - x) * e;
	} else{
		ll x = min(a, d);
		ans = x * e + min(min(b,c), d - x) * f;
	}
	cout << ans << endl;
}
