#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll n; cin >> n;
	vector<set<ll>> adj_dir(n + 1), adj_undir(n + 1);
	for(int i=0;i < n - 1;i++){
		ll s,d; cin >> s >> d;
		adj_dir[s].insert(d);adj_undir[s].insert(d);adj_undir[d].insert(s);
	}
	vector<ll> redInPath(n + 1, 0), dist(n + 1, 0), vis(n + 1, 0);
	queue<ll> q;
	q.push(1);vis[1] = 1;dist[1] = 0; redInPath[1] = 0;
	ll total = 0;
	while(!q.empty()){
		ll top = q.front();q.pop();
		for(auto it:adj_undir[top]){
			if(!vis[it]){
				q.push(it);vis[it] = 1;
				dist[it] = dist[top] + 1;
				ll ulti_edge = (adj_dir[top].find(it) == adj_dir[top].end());
				redInPath[it] = redInPath[top] + ulti_edge;
				total += ulti_edge;
			}
		}
	}
	map<ll,vector<ll>> reverse_edge;
	for(int i = 1;i <= n;i++){
		reverse_edge[total - redInPath[i] + dist[i] - redInPath[i]].push_back(i);
	}
	cout << reverse_edge.begin()->first << endl;
	for(auto it:reverse_edge.begin()->second)cout << it << " ";cout << endl;
}