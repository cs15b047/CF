#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll n; scanf("%lld",&n);
	vector<ll> s(n);for(ll i=0;i<n;i++)scanf("%lld",&s[i]);
	set<ll> S;S.clear();for(ll i=0;i<n;i++)S.insert(s[i]);
	vector<ll>new_S;new_S.clear();for(auto it:S)new_S.push_back(it);
	map<ll, set<pair<ll,ll>>> edges;edges.clear();
	ll sz = new_S.size();

	// for(auto it:new_S)cout << it << " ";cout << endl;

	for(ll i=0;i < sz - 1;i++){
		edges[new_S[i+1] - new_S[i]].insert(make_pair(i, i + 1));
	}

	// for(auto it: edges){
	// 	cout << it.first << ":" << endl;
	// 	for(auto it2:it.second)cout << it2.first << " " << it2.second <<endl;
	// }

	map<ll,ll> diff_to_answer,components; diff_to_answer.clear(); components.clear();
	diff_to_answer[0] = sz;
	components[0] = sz;
	for(auto it: edges){
		ll diff = it.first, prev_diff = diff_to_answer.rbegin()->first, prev_cmp = components[prev_diff];
		ll base_ans = diff_to_answer.rbegin()->second + (diff - prev_diff - 1) * prev_cmp + (prev_cmp - it.second.size()) ;
		components[diff] = prev_cmp - it.second.size() ;
		diff_to_answer[diff] = base_ans;
	}
	// for(auto it: diff_to_answer)cout << it.first << " " << it.second << endl;
	// cout << "#####################yo#####################" << endl;
	// for(auto it: components)cout << it.first << " " << it.second << endl;

	ll q; cin >> q;
	for(ll i=0;i<q;i++){
		ll l,r;cin >> l >> r;
		ll d = r - l ;
		ll answer = 0;
		if(n == 1)answer = d + 1;
		else{
			auto it = diff_to_answer.upper_bound(d);
			it--;
			answer = it->second;
			answer += (d - it->first) * components[it->first];
		}
		cout << answer << " " ;
	}
}