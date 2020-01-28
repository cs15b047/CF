#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll num_nodes;
vector<ll> crossing_paths, subtree_size, visited, parent;
vector<set<ll>> adj_list;

void calc_subtree_size(ll node){
	visited[node] = 1;
	for(auto nbh: adj_list[node]){
		if(!visited[nbh]){
			parent[nbh] = node;
			calc_subtree_size(nbh);
			subtree_size[node] += subtree_size[nbh];
		}
	}
}

int main(){
	scanf("%lld",&num_nodes);
	adj_list.resize(num_nodes + 1);
	vector<ll> src(num_nodes), dest(num_nodes), lengths(num_nodes);
	for(int i = 1;i <= num_nodes - 1;i++){
		scanf("%lld%lld%lld",&src[i], &dest[i], &lengths[i]);
		adj_list[src[i]].insert(dest[i]);
		adj_list[dest[i]].insert(src[i]);
	}
	crossing_paths.resize(num_nodes);
	parent.resize(num_nodes + 1, -1);
	subtree_size.resize(num_nodes + 1, 1);
	visited.resize(num_nodes + 1, 0);

	ll all_pth_len_sum = 0;

	// root at 1
	calc_subtree_size(1);

	for(int i = 1;i <= num_nodes - 1;i++){
		ll node = dest[i], node_parent = src[i];
		if(parent[src[i]] == dest[i]){
			node = src[i];
		}
		crossing_paths[i] = subtree_size[node] * (num_nodes - subtree_size[node]);
		all_pth_len_sum += crossing_paths[i] * lengths[i];
	}

	ll num_queries;
	scanf("%lld",&num_queries);
	for(int i = 0;i < num_queries;i++){
		ll edge_idx, new_len;
		scanf("%lld%lld",&edge_idx, &new_len);
		all_pth_len_sum -= (crossing_paths[edge_idx] * (lengths[edge_idx] - new_len));
		lengths[edge_idx] = new_len;
		double answer = (double)(all_pth_len_sum * 2 * 3)/(double)(num_nodes * (num_nodes - 1));
		printf("%.10lf\n", answer);
	}



}