#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll n; cin >> n ;
	vector<ll> a(n),f(n);for(int i=0;i<n;i++)cin >> a[i];
	map<ll,ll> ele_cnt;
	for(int i=0;i<n;i++){
		ele_cnt[a[i]]++;
		f[i] = ele_cnt[a[i]];
	}
	multiset<ll> myset;myset.insert(f[0]);
	ll answer = 0;
	for(int j=1;j<n;j++){
		auto it = myset.upper_bound(ele_cnt[a[j]] - f[j] + 1);
		answer +=  (it - myset.begin());
	}
}