// C. Pick Heroes  CF# Mail Ru round 3
// Pick according to judge if he plays optimally, selecting heroes from pairs
// Whenever chance comes --> Start picking higher one from pair heroes and after that start picking from normal ones in descending order
#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll n,m; cin >> n >> m;
	vector<ll> p(2*n + 1);for(int i=1;i<=2*n;i++)cin >> p[i];
	map<ll,ll> pairs;for(int i=0;i<m;i++){ll h1,h2;cin >> h1>>h2; pairs[h1] = h2;pairs[h2] = h1;}
	map<ll,set<ll>> pwr_index;for(int i=1;i<=2*n;i++){if(pairs.find(i) == pairs.end())pwr_index[p[i]].insert(i);}
	ll team;cin >> team;

	if(team == 1){
		ll sz = pairs.size();
		// cout << "Size:"<<sz << endl;
		for(int i = 0 ;i < sz/2 ;i++){
			ll h = pairs.begin()->first,h2 = pairs[h];
			if(p[h] >= p[h2])cout << h << endl;
			else cout << h2 << endl;
			fflush(stdout);
			ll x; cin >> x;
			pairs.erase(h);pairs.erase(h2);
		}
		for(int i = 0;i < n - sz/2 ; i++){
			auto it = pwr_index.rbegin();
			auto it2 = it->second.begin();
			cout << *it2 << endl;
			fflush(stdout);
			it->second.erase(it2);
			if(it->second.empty())pwr_index.erase(it->first);
			ll x;cin >> x; pwr_index[p[x]].erase(x);
			if(pwr_index[p[x]].empty())pwr_index.erase(p[x]);
		}
	}
	else{
		ll i = 0;
		while(i < n){
			ll x; cin >> x;
			if(pairs.find(x) != pairs.end()){
				ll h = pairs[x];
				pairs.erase(x); pairs.erase(h);
				cout << h << endl;fflush(stdout);
			}
			else{
				pwr_index[p[x]].erase(x);
				if(pwr_index[p[x]].empty())pwr_index.erase(p[x]);
				break;
			}
			i++;
		}
		while(!pairs.empty()){
			ll h = pairs.begin()->first,h2 = pairs[h];
			if(p[h] >= p[h2])cout << h << endl;
			else cout << h2 << endl ;
			fflush(stdout);
			ll x; cin >> x;
			pairs.erase(h);pairs.erase(h2);
		}
		while(!pwr_index.empty()){
			auto it = pwr_index.rbegin();
			auto it2 = it->second.begin();
			cout << *it2 << endl;fflush(stdout);
			it->second.erase(it2);
			if(it->second.empty())pwr_index.erase(it->first);
			if(pwr_index.empty())break;
			ll x;cin >> x; pwr_index[p[x]].erase(x);
			if(pwr_index[p[x]].empty())pwr_index.erase(p[x]);
		}
	}

}