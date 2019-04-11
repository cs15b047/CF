#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll n; cin >> n;
	vector<ll> a(n);for(int i=0;i<n;i++)cin >> a[i];
	ll c1 = a[0],i1 = 0,i2;

	for(i2 = n-1;a[i2]==c1;i2--);
	ll ans = i2 - i1;
	i2 = n - 1;
	for(i1 =0;a[i2]==a[i1];i1++);
	ans = max(ans,i2 - i1);
	cout << ans << endl;
}