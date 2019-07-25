#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;
ll mod = 1e9+7;
bool cmp(pair<ll,ll> a, pair<ll,ll> b){
	return a.second < b.second;
}
vector<ll> cost, ways, vis;
vector<set<ll>> adj;
vector<pair<ll,ll>> dim;
void dfs(ll node){
	vis[node] = 1;
	cost[node] = 0;
	if(adj[node].empty()){ways[node] = 1;return;}
	ll cst = 1e18;
	map<ll,ll> mymap;
	for(auto it: adj[node]){
		if(!vis[it]){
			dfs(it);
			mymap[it] = cost[it] + dim[it].second - dim[node].first;
			cst = min(cst, cost[it] + dim[it].second - dim[node].first);
		}
	}
	cost[node] = cst;
	for(auto it:mymap){
		if(it.second == cst)ways[node] = (ways[node] + ways[it.first]) % mod;
	}
}

int main(){
	ll n; scanf("%lld",&n);
	cost.resize(n + 1);vis.resize(n + 1);ways.resize(n + 1);
	dim.resize(n); for(int i=0;i<n;i++)scanf("%lld%lld",&dim[i].first, &dim[i].second);
	vector<ll> idx(n), inner(n);sort(dim.begin(), dim.end(), cmp);
	for(int i=0;i<n;i++){idx[i] = i; inner[i] = dim[i].second;}

	set<ll> dist_in, dist_out;for(int i=0;i<n;i++){dist_in.insert(dim[i].second);dist_out.insert(dim[i].first);}

	adj.resize(n + 1);
	vector<ll> indegree(n + 1, 0);
	for(int i=0;i<n;i++){
		ll lower_idx, upper_idx;
		lower_idx = lower_bound(inner.begin(), inner.end(), dim[i].first) - inner.begin();
		auto it = dist_out.find(dim[i].first);++it;
		ll upper_lim = 1e18;
		if(it != dist_out.end()){
			upper_lim = *it;
		}
		ll index = lower_idx;
		while(index < n && inner[index] >= dim[i].first && inner[index] < upper_lim){
			adj[i].insert(index);
			index++;
			indegree[index]++;
		}
	}
	for(int i=0;i<n;i++){
		if(indegree[i] == 0)adj[n].insert(i);
	}
	for(int i=0;i<n;i++)cout << i << ": " << dim[i].first << " " << dim[i].second << endl;
	for(int i=0;i<=n;i++){
		cout << i << ": ";
		for(auto it:adj[i])cout << it << " " ;cout << endl;
	}
	dfs(n);
	cout << ways[n] << endl;
}