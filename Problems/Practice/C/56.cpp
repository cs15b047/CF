#include <bits/stdc++.h>
using namespace std ;

typedef long long int ll ;
ll high = 1e15;
int main(){
	ll n,x;cin>>n>>x;
	vector<vector<ll>> V(n);
	for(int i=0;i<n;i++){
		V[i].resize(3);
		scanf("%lld%lld%lld",&V[i][0],&V[i][1],&V[i][2]);
	}
	sort(V.begin(),V.end());
	map<ll,pair<vector<ll>,vector<ll>>> mymap ;

	for(int i=0;i<n;i++){
		mymap[V[i][1] - V[i][0] + 1].first.push_back(i) ;
	}

	for(auto map_itr: mymap){
		vector<ll> v1 = map_itr.second.first, v2 ; // ind list
		v2.resize(v1.size());
		v2.back() = V[v1.back()][2];
		for(int i=v1.size()-2;i>=0;i--){
			v2[i] = min(v2[i+1],V[v1[i]][2]) ;
		}
		mymap[map_itr.first].second = v2 ;
	}
	ll ans = high ;
	for(auto map_itr: mymap){
		vector<ll> v, rem_v; v = map_itr.second.first;
		if(mymap.find(x - map_itr.first) == mymap.end())continue;
		else{
			rem_v = mymap[x - map_itr.first].first;
			vector<ll> lefts; for(auto tmp:rem_v)lefts.push_back(V[tmp][0]) ;
			for(int i=0;i<v.size();i++){
				int right_first = V[v[i]][1] ;
				auto first_allowed = upper_bound(lefts.begin(), lefts.end(), right_first);
				if(first_allowed != lefts.end()){
					ll index = first_allowed - lefts.begin();
					ans = min(ans, V[v[i]][2] + mymap[x - map_itr.first].second[index]) ;
				}
			}
		}
	}
	if(ans == high)cout << -1 << endl ;
	else cout << ans << endl ;


}