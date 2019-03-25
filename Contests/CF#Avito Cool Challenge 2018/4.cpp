#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector< map<ll,ll> > adj,adj2;

vector<ll>parent, is_special, height ;
map<ll,ll> comp_map;

bool mycomp(pair<ll,ll> e1, pair<ll,ll> e2){
	return adj[e1.first][e1.second] < adj[e2.first][e2.second] ;
}

ll find(ll vtx){
	if(parent[vtx] < 0)return vtx;
	else{
		parent[vtx] = find(parent[vtx]) ;
		return parent[vtx] ;
	}
}
vector<ll>special;
set<ll>sp_v;
map<ll,ll>vis;
ll dfs(ll v){
	vis[v] = 1;
	ll ans = 0;
	if(sp_v.find(v) != sp_v.end())ans++;
	for(auto it:adj[v]){
		if(!vis[it.first]){
			ans += dfs(it.first);
		}
	}
	return ans ;
}


int main(){
	ll n, m, k;cin >> n >> m >> k ;
	special.resize(k);for(int i=0;i<k;i++)scanf("%lld",&special[i]);
	for(auto it:special)sp_v.insert(it);
	adj.resize(n+1);
	for(int i=0;i<m;i++){
		ll s,d,w;scanf("%lld%lld%lld",&s,&d,&w);
		if(s == d)continue;
		if((adj[s].find(d) == adj[s].end()) || adj[s][d] > w){
			adj[s][d] = w;
			adj[d][s] = w;
		}
	}
	vector<pair<ll,ll>>edges, new_edges;
	for(int i=1;i<=n;i++){
		for(auto edge:adj[i]){
			edges.push_back(make_pair(i, edge.first));
		}
	}
	sort(edges.begin(),edges.end(),mycomp);

	parent.resize(n+1); is_special.resize(n+1); height.resize(n+1);

	for(int i=1;i<=n;i++)parent[i] = -1;
	for(int i=1;i<=n;i++)height[i] = 1;
	for(int i=0;i<k;i++)is_special[special[i]] = 1;

	ll answer = 0;
	for(int i=0;i<edges.size();i++){
		ll comp1 = find(edges[i].first),comp2 = find(edges[i].second);
		// cout << edges[i].first << " " << edges[i].second << endl;
		// cout << comp1 << " " << comp2 << endl ;
		
		if(comp1 != comp2){
			if(is_special[comp1] == 1 && is_special[comp2] == 1){
				answer = max(answer, adj[edges[i].first][edges[i].second]);
				// cout << "Updating answer based on: " << edges[i].first << " " << edges[i].second << endl ;
			}
			else if(is_special[comp1] == 1 || is_special[comp2] == 1){
				is_special[comp1] = 1; is_special[comp2] = 1;
			}

			if(height[comp1] > height[comp2]){
				parent[comp1] += parent[comp2] ;
				parent[comp2] = comp1 ;
			}
			else if(height[comp1] < height[comp2]){
				parent[comp2] += parent[comp1] ;	
				parent[comp1] = comp2 ;
			}
			else if(height[comp1] == height[comp2]){
				parent[comp1] += parent[comp2] ;
				parent[comp2] = comp1 ;
				height[comp1]++;
			}
			new_edges.push_back(edges[i]);
		}
	}
	
	// adj2.resize(n+1);
	// for(auto it:new_edges){
	// 	cout << it.first << " " << it.second << endl;
	// 	adj2[it.first][it.second] = adj[it.first][it.second];
	// 	adj2[it.second][it.first] = adj[it.second][it.first];
	// }
	// for(int i=1;i<=n;i++){
	// 	for(auto it:adj2[i])cout << it.first << " ";cout << endl;
	// }
	for(int i=0;i<k;i++)cout << answer << " ";cout << endl ;
}