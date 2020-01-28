#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll t; scanf("%lld",&t);
	for(int q = 0; q < t;q++){
		ll m, n; cin >> n  >> m;
		vector<ll> arr(n);for(int i = 0;i < n ;i++)cin >> arr[i];
		map<ll,ll> val_idx;for(int i = 0;i < n ;i++)val_idx[arr[i]] = i + 1;
		vector<ll> reqd_list(m);for(int i = 0;i < m;i++)cin >> reqd_list[i];
		vector<ll> idx_list(m);for(int i = 0;i < m;i++)idx_list[i] = val_idx[reqd_list[i]];

		ll mxm = -1;
		ll done = 0;
		ll answer = 0;
		for(ll i = 0; i < m; i++){
			if(idx_list[i] > mxm){
				answer += 2 * (idx_list[i] - 1 - done) + 1;
				mxm = idx_list[i];
			} else {
				answer++;
			}
			done++;
		}
		cout << answer << endl;
	}
}