//D. Decorate Apple Tree - mail ru cup round 3
// calculate leaf counts for each subtree and answer acc to that
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<set<ll>> adj;
vector<ll> leaf_count;

void dfs(ll root){
	leaf_count[root] = 0;
	if(adj[root].empty()){
		leaf_count[root] = 1;
		return;
	}
	for(auto nbh:adj[root]){
		dfs(nbh);
		leaf_count[root] += leaf_count[nbh];
	}
}

int main(){
	ll n ; cin >> n ;
	adj.resize(n+1);leaf_count.resize(n+1);
	for(ll i=2;i<=n;i++){
		ll parent;cin >> parent ;
		adj[parent].insert(i);
	}
	dfs(1);

	map<ll,ll> num_leaves_to_num_nodes;
	for(int i=1;i<=n;i++){
		num_leaves_to_num_nodes[leaf_count[i]]++;
	}
	ll curr = 1;
	for(auto it:num_leaves_to_num_nodes){
		for(int itr = curr;itr < curr + it.second;itr++){
			cout << it.first << " " ;
		}
		curr += it.second ;
	}
}