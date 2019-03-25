#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll n; cin >> n;
	vector<ll>a(n);
	for (int i = 0; i < n; ++i)cin >> a[i];
	ll ans = 0,sum=0;
	for (int i = 0; i < n; ++i){
		ans = max(ans, a[i]);
		sum +=a[i];
	}

	ll ans2 = (sum / (n - 1)) + ((sum % (n - 1)) != 0) ;
	ans = max(ans, ans2);
	cout << ans << endl;
}