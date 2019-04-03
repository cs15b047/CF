#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

ll n,k;
vector<ll> ele,cnt;
vector<ll> prefix_cnt, prefix_ele_cnt;

ll bin_search(ll x){
	ll l = 1, r = x,m = (l + r)/2;

	while(l < r){
		m = (l+r)/2;
		ll expr = ele[x]*(prefix_cnt[x] - prefix_cnt[m - 1]) - (prefix_ele_cnt[x] - prefix_ele_cnt[m - 1]);
		if(k >= expr){
			r = m ;
		}
		else{
			l = m + 1;
		}
	}
	return l ;
}

int main(){
	cin >> n >> k ;
	vector<ll> a(n);for(int i=0;i<n;i++)cin >> a[i];
	map<ll,ll> ele_cnt;for(int i=0;i<n;i++)ele_cnt[a[i]]++;
	
	ele.push_back(0);cnt.push_back(0);
	for(auto it:ele_cnt){ele.push_back(it.first);cnt.push_back(it.second);}
	assert(cnt.size() == ele.size());
	ll fin_ans = cnt[0],fin_num=ele[0], sz = cnt.size();
	
	prefix_cnt.resize(sz);prefix_ele_cnt.resize(sz);

	prefix_cnt[0] = cnt[0];prefix_ele_cnt[0] = ele[0] * cnt[0] ;

	for(int i = 1;i < sz ;i++){
		prefix_cnt[i] = prefix_cnt[i-1] + cnt[i];
		prefix_ele_cnt[i] = prefix_ele_cnt[i-1] + ele[i]*cnt[i];
	}

	for(int i = 1;i < sz ;i++){
		ll idx = bin_search(i);
		ll ans =0;
		if(idx > 1){
			ll m = idx,x=i;
			ll expr = ele[x]*(prefix_cnt[x] - prefix_cnt[m - 1]) - (prefix_ele_cnt[x] - prefix_ele_cnt[m - 1]);
			ll remn = k - expr;			
			ans += (remn/(ele[i] - ele[idx - 1])) ;
		}
		ans += (prefix_cnt[i] - prefix_cnt[idx - 1]);

		if(ans > fin_ans){
			fin_ans = ans;
			fin_num = ele[i];
		}
	}
	cout << fin_ans << " " << fin_num << endl;
}