#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;
vector<bool> visited;
vector<set<ll>> adj;

ll dfs(ll node){
	ll cnt = 1;
	visited[node] = 1;
	for(auto nbh:adj[node]){
		if(!visited[nbh]){
			cnt += dfs(nbh);
		}
	}
	return cnt ;
}

int main(){
	ll n; cin >> n;
	vector<pair<ll,ll>> edges(n + 1);
	adj.clear();adj.resize(n + 1);
	visited.clear();visited.resize(n + 1);
	for(ll i = 1;i <= n- 1;i++){
		ll s, d;cin >> s >> d;
		adj[s].insert(d);adj[d].insert(s);
		edges[i - 1] = make_pair(s,d);
	}
	set<pair<ll,ll>> answer;answer.clear();

	for(ll i = 0;i < n - 1;i++){
		for(ll j =1;j<=n;j++)visited[j] = 0;

		adj[edges[i].first].erase(edges[i].second);
		adj[edges[i].second].erase(edges[i].first);

		ll src = edges[i].first, dest = edges[i].second;
		ll cnt = dfs(src);
		if(cnt != n - 1){
			answer.insert(make_pair(cnt, n - 1 - cnt));
			answer.insert(make_pair(n - 1 - cnt, cnt));
		}
		for(ll j =1;j<=n;j++)visited[j] = 0;
		cnt = dfs(dest);
		if(cnt != n - 1){
			answer.insert(make_pair(cnt, n - 1 - cnt));
			answer.insert(make_pair(n - 1 - cnt, cnt));
		}

		adj[edges[i].first].insert(edges[i].second);
		adj[edges[i].second].insert(edges[i].first);
	}
	cout << answer.size() << endl ;
	for(auto it:answer)cout << it.first << " " << it.second << endl ;

}