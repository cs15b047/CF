// D. Robot Rapping Results Report --> CROC 2016 Elmn round
// Step by step TopSort, such that in each stage only 1 node can be eliminated. WHen multiple can get eliminated, stop and add edges till only 1 remains w/o incoming edges
#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll n, m; cin >> n >> m;
	vector<pair<ll,ll>> edges(m);
	for(ll i = 0; i < m; i++)cin >> edges[i].first >> edges[i].second ;

	set<ll> zero_indegree;
	vector<set<ll>> adj(n + 1);
	vector<ll> indegree(n + 1);
	vector<bool> visited(n + 1);
	for(ll i=1;i<=n;i++)zero_indegree.insert(i);

	ll index = 0, num_visited = 0;

	while((index < m) && (num_visited < n)){
		while((index < m) && (zero_indegree.size() > 1)){
			if(!visited[edges[index].first]){
				adj[edges[index].first].insert(edges[index].second);
				zero_indegree.erase(edges[index].second);
				indegree[edges[index].second]++;
			}
			index++;
		}
		while(zero_indegree.size() == 1){
			ll curr = *zero_indegree.begin();
			zero_indegree.erase(curr);
			visited[curr] = 1;
			num_visited++;
			set<ll> nbhs = adj[curr];
			for(auto nbh:nbhs){
				adj[curr].erase(nbh);
				indegree[nbh]--;
				if(indegree[nbh] == 0)zero_indegree.insert(nbh);
			}
		}
	}
	if(num_visited == n)cout << index << endl;
	else cout << -1 << endl;
}