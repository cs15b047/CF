#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;
vector<ll> parents;

ll find(ll node){
	if(parents[node] < 0)return node;
	parents[node] = find(parents[node]);
	return parents[node];
}

void disj_union(ll node1, ll node2){
	node1 = find(node1);node2 = find(node2);
	if(abs(parents[node1]) > abs(node2)){
		parents[node2] = node1;
	}
	else if(abs(parents[node1]) < abs(node2)){
		parents[node1] = node2;
	}
	else{
		parents[node2] = node1;
		parents[node1]--;
	}
}

int main(){
	ll n; scanf("%lld",&n);
	vector<ll> x(n), y(n);
	for (int i = 0; i < n - 1; ++i)scanf("%lld%lld",&x[i],&y[i]);

	map<ll,vector<ll>> Partial_orders;
	vector<ll> tmp;
	for(int i=1;i<=n;i++){
		tmp.clear();tmp.push_back(i);
		Partial_orders[i] = tmp;
	}
	parents.resize(n + 1);
	for(int i=1;i<=n;i++)parents[i] = -1;

	for(int i=0;i<n - 1;i++){
		ll node1 = find(x[i]), node2 = find(y[i]);
		disj_union(node1, node2);
		if(Partial_orders[node1].size() > Partial_orders[node2].size()){
			Partial_orders[node1].insert(Partial_orders[node1].end(), Partial_orders[node2].begin(), Partial_orders[node2].end());
			Partial_orders.erase(node2);
			if(parents[node2] < 0){
				Partial_orders[node2] = Partial_orders[node1];
				Partial_orders.erase(node1);
			}
		}
		else{
			Partial_orders[node2].insert(Partial_orders[node2].end(), Partial_orders[node1].begin(), Partial_orders[node1].end());
			Partial_orders.erase(node1);
			if(parents[node1] < 0){
				Partial_orders[node1] = Partial_orders[node2];
				Partial_orders.erase(node2);
			}
		}
	}
	ll last = find(1); // any find
	for(auto it: Partial_orders[last]){
		printf("%lld ",it );
	}
}