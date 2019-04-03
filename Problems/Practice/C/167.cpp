#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll x,n,k; cin >> n >> x >> k;
	vector<ll> a(n);for(int i=0;i<n;i++)cin >> a[i];
	sort(a.begin(),a.end());

	ll answer = 0;
	for(int i=0;i<n;i++){
		ll strt = a[i];
		if(k == 0 && (a[i] % x == 0)){
			continue;
		}
		else if(k == 0 && (a[i] % x != 0)){
			// cout << strt << endl;
			ll end_1 = strt;
			ll end_2 = strt + (x - (strt % x) - 1);
			ll idx1 = lower_bound(a.begin(),a.end(), end_1) - a.begin();
			ll idx2 = upper_bound(a.begin(),a.end(), end_2) - a.begin();
			ll num_in_range = 0;
			num_in_range = idx2 - idx1 ;

			// cout << end_1 << " " << end_2 << " " << idx1 << " " << idx2 << " " << num_in_range << endl;

			answer += num_in_range;
		}
		else{
			// cout << strt << endl;
			if(strt % x != 0)strt += (x - (strt % x)) ;
			ll end_1 = strt + (k - 1)*x;
			ll end_2 = strt + (k)*x - 1;
			ll idx1 = lower_bound(a.begin(),a.end(), end_1) - a.begin();
			ll idx2 = upper_bound(a.begin(),a.end(), end_2) - a.begin();
			ll num_in_range = 0;
			if(idx1 != n){
				num_in_range = idx2 - idx1 ;
			}
			// cout << end_1 << " " << end_2 << " " << idx1 << " " << idx2 << " " << num_in_range << endl;

			answer += num_in_range;
		}
	}
	cout << answer << endl ;

}