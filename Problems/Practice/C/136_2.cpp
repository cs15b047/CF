#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

vector<vector<ll>> dist;
vector<ll> answer;
vector<bool> visited;
vector<set<ll>> adj;
ll n, k;
void dfs(ll node){
	visited[node] = true;
	vector<ll> tot(k + 1, 0);
	answer[node] = 0;
	for(auto nbh: adj[node]){
		if(!visited[nbh]){
			dfs(nbh);
			answer[node] += answer[nbh];
			for(int x = 0;x <= k;x++)tot[x] += dist[nbh][x];
		}
	}
	answer[node] += tot[k - 1];

	for(auto nbh: adj[node]){
		for(int x = 0; x <= k - 2;x++){
			ll num_nodes_1 = dist[nbh][x], num_nodes_2 = tot[k - 2 - x] - dist[nbh][k - 2 - x] ;
			answer[node] += (num_nodes_1 * num_nodes_2);
		}
	}
	dist[node][0] = 1;
	for(int x = 1; x <= k; x++){
		dist[node][x] = tot[x - 1];
	}
}


int main(){
	cin >> n >> k;
	adj.resize(n + 1);
	for(int i = 1;i <= n - 1;i++){
		ll s, d; cin >> s >> d;
		adj[s].insert(d);adj[d].insert(s);
	}
	dist.resize(n + 1, vector<ll>(k + 1, 0));
	answer.resize(n + 1, 0);
	visited.resize(n + 1, false);

	dfs(1);

	for(int i = 1;i <= n;i++)cout << i << " : " << answer[i] << endl;
}