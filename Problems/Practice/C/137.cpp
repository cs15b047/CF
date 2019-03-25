// 696B	:Puzzles # 362 -div 1
// ET(x) = ET(parent) + 1 + (sum of subtrees of all siblings/2)   , (sum of subtrees of all siblings/2) ==> Avg Time
#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

vector<double> exp_time, subtree_size;
vector<set<ll>> adj;
void dfs1(ll node){
	subtree_size[node] = 1;
	for(auto nbh: adj[node]){
		dfs1(nbh);
		subtree_size[node] += subtree_size[nbh];
	}
}

void dfs2(ll node){
	for(auto nbh: adj[node]){
		exp_time[nbh] = exp_time[node] + ((double)1 + (subtree_size[node] - 1 - subtree_size[nbh] )/(double)2) ;
		dfs2(nbh);
	}
}

int main(){
	ll n; cin >> n ;
	exp_time.clear();exp_time.resize(n + 1);subtree_size.clear();subtree_size.resize(n + 1);
	vector<ll> parent(n + 1);
	adj.resize(n + 1);
	
	for(ll i = 2;i <= n ; i++){
		scanf("%lld",&parent[i]);
		adj[parent[i]].insert(i);
	}
	dfs1(1);
	exp_time[1] = 1.0;
	dfs2(1);

	for(ll i = 1;i <=n ; i++){
		printf("%.7lf ",exp_time[i] );
	}
}