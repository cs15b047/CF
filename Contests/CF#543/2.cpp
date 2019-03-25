#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll n;cin >> n;
	vector<ll>a(n);for(int i=0;i<n;i++)cin >> a[i];	
	map<ll,ll> sum_cnt;
	for(int i=0;i<n;i++){
		for(int j=i + 1;j<n;j++){
			sum_cnt[a[i] + a[j]]++;
		}
	}
	ll ans = 0;
	for(auto it:sum_cnt){
		ans = max(ans, it.second);
	}
	cout <<ans<< endl;
}