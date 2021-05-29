#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll tests;
ll num_vtx, num_edges, max_limit;
vector<pair<ll,ll>> edges;
map<pair<ll,ll>, ll> wt;

vector<ll> parent;
set<ll> edge_idxs;

bool cmp(pair<ll,ll> p1, pair<ll,ll> p2) {
	return wt[p1] < wt[p2];
}

void init(){
	wt.clear();
	edges.clear();
	parent.clear();
	edge_idxs.clear();
}

void get_input(){
	scanf("%lld%lld%lld", &num_vtx, &num_edges, &max_limit);
	parent.resize(num_vtx + 1, -1);
	for(int i = 0;i < num_edges;i++){
		ll src, dest, limit; scanf("%lld%lld%lld", &src, &dest, &limit);
		pair<ll,ll> edge = make_pair(src, dest);
		edges.push_back(edge);
		wt[edge] = limit;
	}
	sort(edges.begin(), edges.end(), cmp);
}


ll find(ll node){
	if(parent[node] < 0)return node;
	parent[node] = find(parent[node]);
	return parent[node];
}

void union_rank(ll node1, ll node2){
	if(llabs(parent[node1]) < llabs(parent[node2])){
		parent[node1] = node2;
	} else if(llabs(parent[node1]) > llabs(parent[node2])){
		parent[node2] = node1;
	} else{
		parent[node2] = node1;
		parent[node1]--;
	}
}

ll form_tree(){
	ll taken = 0, i = 0;
	for(;i < num_edges && taken < num_vtx - 1;i++){
		// cout << "Edge index: " << i << ": " << edges[i].first << " " << edges[i].second << endl;
		// for(int j = 1;j <= num_vtx;j++)cout << find(j) << " ";cout << endl;

		ll node1 = find(edges[i].first), node2 = find(edges[i].second);
		if(node1 != node2){
			union_rank(node1, node2);
			taken++;
			edge_idxs.insert(i);
		}
	}
	return i;
}

int main(){
	scanf("%lld", &tests);
	for(int q = 0;q < tests;q++){
		init();
		get_input();
		ll idx = form_tree(); idx--;
		ll ans = llabs(wt[edges[idx]] - max_limit);
		// cout << "idx: " << idx << ", initial ans: " << ans << endl;
		if(wt[edges[idx]] < max_limit){
			for(ll i = idx;i < num_edges;i++){
				ans = min(llabs(wt[edges[i]] - max_limit), ans);
			}
		} else{
			ans = 0;
			for(auto it: edge_idxs){
				if(wt[edges[it]] >= max_limit) ans += (wt[edges[it]] - max_limit);
			}
		}
		printf("%lld\n", ans );
	}


}