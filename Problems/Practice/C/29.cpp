#include <bits/stdc++.h>
using namespace std ;

typedef long long int ll ;

ll bfs(int n, vector<vector<ll>> adj)
{
	map<ll,int> vis, dist ;
	dist[1] = 0;
	queue<ll> q;
	q.push(1);vis[1] = 1;
	while(!q.empty()){
		ll t = q.front(); q.pop();
		if(t == n)return dist[n] ;
		for(auto nbh:adj[t]){
			if(vis.find(nbh) == vis.end()){
				dist[nbh] = dist[t] + 1;
				vis[nbh] = 1;
				q.push(nbh);
			}
		}
	}
	return -1;
}

int main()
{
	int n,m;cin >> n >> m;
	vector<vector<ll>> adj_rl(n+1), adj_rd(n+1) ;
	map<ll,set<ll>> adj2_rl ;
	for(int i=1;i<=m;i++){
		ll s,d ;cin >> s >> d ;
		adj_rl[s].push_back(d);adj_rl[d].push_back(s);
		adj2_rl[s].insert(d);adj2_rl[d].insert(s);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(adj2_rl.find(i) == adj2_rl.end() || adj2_rl[i].find(j) == adj2_rl[i].end())
				adj_rd[i].push_back(j);
		}
	}
	ll ans = 1;
	if(adj2_rl.find(1) != adj2_rl.end() && adj2_rl[1].find(n) != adj2_rl[1].end()){
		ans = bfs(n, adj_rd);
	}
	else{
		ans = bfs(n, adj_rl);
	}
	cout << ans <<endl ;	

}