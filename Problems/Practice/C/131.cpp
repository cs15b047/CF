//D - Colorful Graph	
// Direct computation of colors of nbhs
#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll n, m; cin >> n >> m ;
	vector<ll>colors(n+1);for(int i=1;i<=n;i++)cin >> colors[i];
	vector<set<ll>> adj(n+1);
	for(int i=0;i<m;i++){
		ll s,d;cin >> s >> d;
		adj[s].insert(d);adj[d].insert(s);
	}
	map<ll,set<ll>> Q;
	for(int i=1;i<=n;i++){
		for(auto nbh:adj[i]){
			if(colors[nbh] != colors[i]){
				Q[colors[i]].insert(colors[nbh]);
			}
		}
	}
	ll ans = 0,color = 1e18;
	if(Q.empty()){
		for(int i=1;i<=n;i++)color = min(color, colors[i]);
	}
	else{
		for(auto itr: Q){
			if(itr.second.size() > ans){
				ans = itr.second.size();
				color = itr.first;
			}
		}
	}
	cout << color << endl;
}