#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<ll> representative;
vector<ll> elec_cost, wire_cost;
vector<pair<ll,ll>> city_coords;
vector<pair<ll,ll>> edges;
vector<ll> min_cost_node;

ll dist(pair<ll,ll> pt1, pair<ll,ll> pt2){
	return llabs(pt1.first - pt2.first) + llabs(pt1.second - pt2.second);
}

ll edge_cost(pair<ll,ll> edge){
	return (wire_cost[edge.first] + wire_cost[edge.second]) *
			 dist(city_coords[edge.first], city_coords[edge.second]);
}

bool cmp(pair<ll,ll> edge1, pair<ll,ll> edge2){
	return edge_cost(edge1) < edge_cost(edge2);
}


ll find(ll node){
	if(representative[node] < 0)return node;
	representative[node] = find(representative[node]);
	return representative[node];
}

void union_by_rank(ll node1, ll node2){
	if(llabs(representative[node1]) > llabs(representative[node2])){
		representative[node2] = node1;
		if(elec_cost[min_cost_node[node2]] < elec_cost[min_cost_node[node1]]){
			min_cost_node[node1] = min_cost_node[node2];
		}
	} else if(llabs(representative[node1]) < llabs(representative[node2])){
		representative[node1] = node2;
		if(elec_cost[min_cost_node[node2]] > elec_cost[min_cost_node[node1]]){
			min_cost_node[node2] = min_cost_node[node1];
		}
	} else{
		representative[node2] = node1;
		representative[node1]--;
		if(elec_cost[min_cost_node[node2]] < elec_cost[min_cost_node[node1]]){
			min_cost_node[node1] = min_cost_node[node2];
		}
	}
}


int main(){
	ll num_cities; cin >> num_cities;
	city_coords.resize(num_cities);
	for(int i = 0;i < num_cities;i++)cin >> city_coords[i].first >> city_coords[i].second;
	elec_cost.resize(num_cities);for(int i = 0;i < num_cities;i++)cin >> elec_cost[i];
	wire_cost.resize(num_cities);for(int i = 0;i < num_cities;i++)cin >> wire_cost[i];

	representative.clear();representative.resize(num_cities, -1);
	min_cost_node.resize(num_cities);for(int i = 0;i < num_cities;i++)min_cost_node[i] = i;

	for(int i =0;i < num_cities;i++){
		for(int j = i + 1;j < num_cities;j++){
			edges.push_back(make_pair(i, j));
		}
	}
	// sort edges in order of cost
	sort(edges.begin(), edges.end(), cmp);

	// initially elec at each city
	ll initial_cost = 0;
	for(int i = 0;i < num_cities;i++)initial_cost += elec_cost[i];

	ll num_edges = edges.size();
	vector<pair<ll,ll>> added_edges;
	for(int i = 0;i < num_edges;i++){
		pair<ll,ll> edge = edges[i];
		ll repr1 = find(edge.first), repr2 = find(edge.second);

		// condition to add an edge and remove an elec unit
		if(repr1 != repr2 && edge_cost(edge) < max(elec_cost[min_cost_node[repr1]], elec_cost[min_cost_node[repr2]])){
			initial_cost += (edge_cost(edge) - max(elec_cost[min_cost_node[repr1]], elec_cost[min_cost_node[repr2]]));
			union_by_rank(repr1, repr2);
			// cout << "Add: "<< edge.first << " " << edge.second << endl;
			added_edges.push_back(edge);
		}
	}
	cout << initial_cost << endl;
	vector<ll> elec_nodes;
	for(int i = 0;i < num_cities;i++){
		if(representative[i] < 0){
			elec_nodes.push_back(min_cost_node[i]);
		}
	}
	cout << elec_nodes.size() << endl;
	for(auto it:elec_nodes)cout << it + 1 << " ";cout << endl;
	cout << added_edges.size() << endl;
	for(auto it:added_edges)cout << it.first + 1 << " " << it.second + 1 << endl;
}