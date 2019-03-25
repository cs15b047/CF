#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll n; cin >> n;
	vector<ll>a(n + 1),b(n + 1);
	a[0] = 0; b[0] = 0;
	for(int i=1;i<=n;i++)cin >> a[i] >> b[i] ;

	ll mnm = 0, st = 0;
	ll ans = 1;

	set<ll> done;
	done.insert(0);

	for(int i=1;i<=n;i++){
		ll mnm_d = min(a[i],b[i]);
		if(mnm == mnm_d){
			st = max(a[i],b[i]);
		}
		else{
			ll val = max(mnm_d - st + (done.find(st) == done.end()), (ll)0);
			ans += val;
			if(val > 0){
				done.insert(st);
				done.insert(mnm_d);
			}
			mnm = mnm_d;
			st = max(a[i],b[i]);
		}
	}
	cout << ans << endl;
}