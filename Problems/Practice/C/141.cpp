// D. Edge Deletion --> Edu #54 div 2
//Ans = k steps of Dijkstra
#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;
vector<ll> dist;

class cmp{
public:
	bool operator()(ll a, ll b){
		return ((dist[a] < dist[b]) || ((dist[a] == dist[b]) && (a < b))); 
	}	
};

int main(){
	ll n, m, k; cin >> n >> m >> k;
	vector<set<pair<ll,ll>>> adj(n + 1);
	map<pair<ll,ll>,ll> edges;

	for(ll i = 0; i < m;i++){
		ll s,d,w;cin >>s >> d >> w;
		adj[s].insert(make_pair(d,w));
		adj[d].insert(make_pair(s,w));
		edges[make_pair(s,d)] = i + 1;
		edges[make_pair(d,s)] = i + 1;
	}
	dist.clear();dist.resize(n + 1);
	for(ll i=1;i<=n;i++)dist[i] = 1e18; dist[1] = 0;

	set<ll, cmp> nodes;
	vector<bool> visited(n + 1);

	cout << min(k, n - 1) << endl;

	vector<pair<ll,ll>> corresponding_edge(n + 1);

	nodes.insert(1);
	for(ll i = 0;i < min(k, n - 1);i++){
		// for(auto it:nodes)cout << it << " ";cout << endl ;
		ll top = *nodes.begin();
		// cout << top << " ";
		visited[top] = 1;
		nodes.erase(top);
		for(auto nbh:adj[top]){
			if(!visited[nbh.first]){
				nodes.erase(nbh.first);
				if(dist[nbh.first] > dist[top] + nbh.second){
					dist[nbh.first] = dist[top] + nbh.second;
					// cout << nbh.first << " " << dist[nbh.first] << endl;
					corresponding_edge[nbh.first] = make_pair(top, nbh.first);
				}
				nodes.insert(nbh.first);
			}
		}
		ll new_top = *nodes.begin();
		cout << edges[corresponding_edge[new_top]] << " ";
	}
	cout << endl ;
}