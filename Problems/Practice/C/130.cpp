// C. Checkposts  # 244  - 2
// Get SCCs of graph by doing DFS 2 times, 2nd time after reversing edges

#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;
ll mod = 1e9+7;
vector<ll>visited;
stack<ll> dfs_stk;
set<ll> SCC;
vector<set<ll>> adj;
void dfs(ll node, int second_time){
	visited[node] = 1;
	for(auto nbh: adj[node]){
		if(!visited[nbh]){
			dfs(nbh, second_time);
		}
	}
	if(!second_time)dfs_stk.push(node);
	else SCC.insert(node);
}

void reverse_edges(){
	vector<set<ll>>adj2(adj.size());
	ll n = adj.size() - 1;
	for(int i=1;i<=n;i++){
		for(auto it:adj[i]){
			adj2[it].insert(i);
		}
	}
	adj = adj2;
	adj2.clear();
}

int main(){
	ll n; cin >> n ;
	vector<ll>cost(n+1);for(int i=1;i<=n;i++)cin >> cost[i];
	ll m; cin >> m;
	adj.resize(n+1);
	for(int i=0;i<m;i++){
		ll s,d; cin >> s >> d ;
		adj[s].insert(d);
	}
	visited.clear(); visited.resize(n + 1);
	for(int i=1;i<=n;i++)visited[i] = 0;
	for(int i=1;i<=n;i++){
		if(!visited[i])dfs(i, 0);
	}
	
	reverse_edges();

	ll tot_ans=0, tot_ways=1;

	visited.clear(); visited.resize(n + 1);
	for(int i=1;i<=n;i++)visited[i] = 0;
	while(!dfs_stk.empty()){
		ll top = dfs_stk.top(); dfs_stk.pop();
		SCC.clear();
		if(!visited[top]){
			dfs(top, 1);
			ll ans = 1e18, ways = 0;
			// for(auto it:SCC)cout << it << " ";cout << endl;
			for(auto it:SCC)ans = min(ans, cost[it]);
			for(auto it:SCC)ways += (ans == cost[it]);
			tot_ans += ans;
			tot_ways = (tot_ways * ways) % mod;
		}
	}
	cout << tot_ans << " " << tot_ways << endl ;
}