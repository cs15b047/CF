#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<ll> parent;

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

int main(){
	ll n, m; scanf("%lld%lld",&n,&m);
	vector<set<ll>> adj_list(n + 1);
	parent.resize(n + 1, -1);
	for(int i = 1;i <= m;i++){
		ll src, dest; scanf("%lld%lld",&src, &dest);
		adj_list[src].insert(dest);
		adj_list[dest].insert(src);
	}

	for(int i = 1;i <= n;i++){
		for(int j = i + 1;j <= n;j++){
			ll repr2 = find(j), repr1 = find(i);
			if(repr2 != repr1 && adj_list[i].find(j) == adj_list[i].end()){
				union_rank(repr1, repr2);
			}
		}
	}
	ll num_components = 0;
	for(int i = 1;i <= n;i++){
		if(parent[i] < 0)num_components++;
	}
	printf("%lld\n", num_components - 1);
}