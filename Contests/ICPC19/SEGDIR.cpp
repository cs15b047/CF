#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

bool processvector(vector<pair<ll,ll>> vec){
	if((int)(vec.size()) <= 2)return true;
	else{
		map<ll, pair<ll,ll>> locns;
		for(auto it: vec){
			// begin
			if(locns.find(it.first) == locns.end()){
				locns[it.first] = make_pair(1, 0);	
			} else{
				locns[it.first] = make_pair(locns[it.first].first + 1, locns[it.first].second);
			}
			// end
			if(locns.find(it.second) == locns.end()){
				locns[it.second] = make_pair(0, 1);
			} else{
				locns[it.second] = make_pair(locns[it.second].first, locns[it.second].second + 1);
			}
		}
		ll overlap = 0;
		for(auto it: locns){
			pair<ll,ll> cnts = it.second;
			// process incoming first
			if(overlap + cnts.first > 2)return false;
			// change overlap to diff of in and out
			overlap = overlap + cnts.first - cnts.second;
		}
		return true;
	}
}

int main(){
	ll t; scanf("%lld",&t);
	for(int q = 0;q < t;q++){
		map<ll, vector<pair<ll,ll>>> segs;
		segs.clear();
		ll n; scanf("%lld",&n);
		for(int i = 0; i < n;i++){
			ll l, r, v;scanf("%lld%lld%lld",&l,&r,&v);
			segs[v].push_back(make_pair(l, r));
		}
		bool possible = true;
		for(auto it : segs){
			vector<pair<ll,ll>> vec = it.second;
			bool flag = processvector(vec);
			if(!flag){
				possible = false;
				break;
			}
		}
		if(possible){
			printf("YES\n");
		} else{
			printf("NO\n");
		}
	}
}