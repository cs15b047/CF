#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll n; cin >> n;
	vector<ll> a(n);for(int i=0;i<n;i++)cin >> a[i];
	ll mxm = a[0], idx = 0;
	for(int i=1;i<n;i++){
		if(a[i] > mxm){
			mxm = a[i];idx = i;
		}
	}
	string ans = "YES" ;
	for(int i = idx;i > 0; i--){
		if(a[i] < a[i - 1]){
			ans = "NO";
			break;
		}
	}
	if( ans != "NO"){
		for(int i = idx;i < n - 1; i++){
			if(a[i] < a[i + 1]){
				ans = "NO";
				break;
			}
		}
	}
	cout << ans << endl;
}