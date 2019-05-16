#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;
vector<ll> arr, idx;

bool cmp(ll a, ll b){
	return arr[a] < arr[b];
}

int main(){
	ll n; scanf("%lld",&n);
	arr.resize(n);idx.resize(n); for(int i=0;i<n;i++)scanf("%lld",&arr[i]);
	for(int i=0;i<n;i++)idx[i] = i;
	sort(idx.begin(), idx.end(), cmp);
	// for(auto it:idx)cout << it <<" ";cout << endl;

	vector<ll> suffix_mx(n), suffix_mn(n);
	suffix_mx[n - 1] = idx[n - 1];suffix_mn[n - 1] = idx[n - 1];
	for(int i = n - 2;i >= 0;i--){
		suffix_mx[i] = max(suffix_mx[i + 1], idx[i]);
		suffix_mn[i] = min(suffix_mn[i + 1], idx[i]);
	}
	ll answer = 1e18;
	for(int i=0;i < n - 1;i++){
		// cout << abs(idx[i] - suffix_mx[i+1]) << " " << abs(idx[i] - suffix_mn[i+1]) << endl;
		ll tmp_ans = arr[idx[i]]/max(llabs(idx[i] - suffix_mx[i+1]), llabs(idx[i] - suffix_mn[i+1]));
		answer = min(answer, tmp_ans);
	}
	cout << answer << endl;
}