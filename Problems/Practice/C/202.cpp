// 605B - Lazy Student CF# 335 - 1
// Sort MST edges and non-MST edges, Put MST edges as 1-2-3-4-5.... and non-MST as 3-1, 4-1,4-2,.....
#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll n,m; cin >> n >> m;
	vector<pair<ll,ll>> wts_include(m);for(int i=0;i<m;i++)cin >> wts_include[i].first >> wts_include[i].second;
	map<ll,pair<ll,ll>> mymap;for(int i=0;i<m;i++)mymap[wts_include[i].first] = make_pair((ll)0,(ll)0);
	map<pair<ll,ll>,vector<ll>> ulta;for(int i=0;i<m;i++)ulta[wts_include[i]].push_back(i);
	// for(auto it:ulta){
	// 	cout << it.first.first << " " << it.first.second << " ";
	// 	for(auto it2:it.second)cout << it2 << " ";cout << endl;
	// }
	for(int i=0;i<m;i++){
		if(wts_include[i].second == 0) mymap[wts_include[i].first].first++;
		else mymap[wts_include[i].first].second++;
	}

	ll curr = 1, from = 1,to = 3 ;
	int flag = 0;

	// for(auto it:mymap)cout << it.first << " " << it.second.first << " " << it.second.second << endl;

	vector<set<ll>> adj(n + 1);
	vector<pair<ll,ll>> edges(m);
	for(int i=0;i<m;){
		auto it = mymap.begin();

		if(it->second.second > 0){
			adj[curr].insert(curr + 1);

			pair<ll,ll> mp = make_pair(it->first, 1);
			ll idx = ulta[mp].back();ulta[mp].pop_back();
			edges[idx] = make_pair(curr, curr + 1);
			
			it->second.second--;
			i++;
			curr++;
		}
		else if(it->second.first > 0){
			if(to > curr){flag = 1;break;}
			else{
				adj[from].insert(to);
				// cout << from << " " << to << endl;

				pair<ll,ll> mp = make_pair(it->first, 0);
				// cout << it->first << endl;
				ll idx = ulta[mp].back();
				// cout << idx << endl;
				ulta[mp].pop_back();
				edges[idx] = make_pair(from, to);
				// cout << idx << " " << from  << " " << to << endl;
				
				if(from == to - 2){from = 1; to++;}
				else from++;
				it->second.first--;
			}
			i++;
			// cout << i << endl;
		}
		else mymap.erase(it->first);
	}
	if(flag == 1)cout << -1 << endl;
	else{
		for(int i=0;i<m;i++){
			cout << edges[i].first << " " << edges[i].second << endl;
		}
	}
}