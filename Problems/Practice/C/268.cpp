#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll mod = 998244353;

ll tests;
ll n, k;
vector<ll> a, b_list;

set<ll> b;
map<ll,ll> val_to_idx, idx_to_val;

vector<ll> previous, next;

void init(){
	a.clear();
	b_list.clear();
	b.clear();
	val_to_idx.clear();
	idx_to_val.clear();
}

void take_input(){
	scanf("%lld%lld", &n, &k);
	for(int i = 0;i < n;i++){
		ll val; scanf("%lld", &val);
		a.push_back(val);
		val_to_idx[val] = i;
		idx_to_val[i] = val;
	}
	for(int i = 0;i < k;i++){
		ll val; scanf("%lld", &val);
		b_list.push_back(val);
		b.insert(val);
	}
}

ll calc_ans(){
	ll ans = 1;
	for(auto ele: b_list){
		ll pos = val_to_idx[ele];
		ll nbhs_possible = 0, left = 0, right = 0;
		auto it = idx_to_val.find(pos);

		// cout << "Index: " << it->first << " " << idx_to_val.begin()->first << " " << idx_to_val.rbegin()->first << endl;

		// if not in lefttmost end
		if(it->first != idx_to_val.begin()->first){
			--it;
			auto b_pos = b.find(it->second);
			++it;

			if(b_pos == b.end())left = 1;
		}

		// if not in rightmost end
		if(it->first != idx_to_val.rbegin()->first){
			++it;
			auto b_pos = b.find(it->second);
			--it;

			if(b_pos == b.end())right = 1;
		}
		// cout << ele << " " << pos << " " << left << " " << right << endl;
		nbhs_possible = left + right;
		if (nbhs_possible == 0)return 0;
		if(nbhs_possible == 2) ans = (ans * 2) % mod;

		
		// choose which one to delete from a: if left available --> left, else right
		if(left != 0) --it;
		else ++it;

		// update states for b and a
		b.erase(ele);

		ll idx = it->first, val = it->second;
		idx_to_val.erase(idx);
		val_to_idx.erase(val);
	}

	return ans;
}

int main(){
	scanf("%lld", &tests);
	for(int t = 0;t < tests; t++){
		init();
		take_input();
		ll ans = calc_ans();
		printf("%lld\n", ans);
	}

}