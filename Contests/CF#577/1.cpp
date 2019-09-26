#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll n, m; cin >> n >> m;
	vector<string> ans(n);
	vector<ll> a(m);
	for(int i=0;i<n;i++)cin >> ans[i];
	for(int i=0;i<m;i++)cin >> a[i];
	vector<vector<ll>>cnt(m, vector<ll>(5, 0));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cnt[j][ans[i][j] - 'A']++;
		}
	}
	ll answer = 0;
	for(int i = 0;i < m;i++){
		ll mxm = cnt[i][0], arg = 0;
		for(int j = 1;j < 5;j++){
			if(mxm < cnt[i][j]){arg = j;mxm = cnt[i][j];}
		}
		answer += mxm * a[i];
	}
	cout << answer << endl;
}