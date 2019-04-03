#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll n; cin >> n;
	map<ll,set<pair<ll,ll>>> diff_pt_map; diff_pt_map.clear();
	map<ll,set<ll>> w_to_idx; w_to_idx.clear();
	map<ll,vector<ll>> pts;
	for(int i=0;i<n;i++){
		ll x,y;cin>>x>>y;
		diff_pt_map[y - x].insert(make_pair(x,y));
		pts[x].push_back(y);
	}

	for(auto &it: pts){
		sort(it.second.begin(),it.second.end());
	}

	for(int i=0;i<n;i++){
		ll w; cin>> w;
		w_to_idx[w].insert(i);
	}
	int flag = 0;
	vector<pair<ll,ll>> answer(n);
	map<pair<ll,ll>, ll> rev_ans;
	for(auto it: diff_pt_map){
		if((w_to_idx.find(it.first) == w_to_idx.end()) || (it.second.size() != w_to_idx[it.first].size())){
			flag = 1;
			break;
		}
		else{
			auto it2 = it.second.begin();
			auto it3 = w_to_idx[it.first].begin();
			for(;it2 != it.second.end() && it3 != w_to_idx[it.first].end();it2++,it3++){
				answer[*it3] = *it2;
				rev_ans[*it2] = *it3;
			}
		}
	}
	if(flag == 1)cout << "NO" << endl;
	else{
		// cout << "yoyo" << endl;
		bool flag2 = true;
		for(auto it: pts){
			for(int i = 0;i < it.second.size();i++){
				ll it2 = it.second[i];
				if(pts.find(it.first - 1) != pts.end())flag2 = flag2 && (rev_ans[make_pair(it.first, it2)] > rev_ans[make_pair(it.first - 1, it2)]) ;
				if(i != 0)flag2 = flag2 && (rev_ans[make_pair(it.first, it2)] > rev_ans[make_pair(it.first, it.second[i-1])]) ;
				if(!flag2)break;
			}
			if(!flag2)break;
		}

		if(flag2){
			cout << "YES" << endl;
			for(int i=0;i<n;i++)cout << answer[i].first << " " << answer[i].second << endl;
		}
		else cout << "NO" << endl;
	}
}