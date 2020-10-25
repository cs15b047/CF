#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll tests;
ll num_cities, num_citizens;
vector<ll> city_pop;
vector<ll> happ_idx;
vector<set<ll>> adj_list;

vector<ll> subtree_size;
vector<bool> visited;
vector<pair<ll,ll>> people_distrbn;
vector<ll> parent;

bool valid;

void print(vector<ll>& v){
	for(auto ele: v){
		cout << ele << " ";
	}
	cout << endl;
}

void print(vector<pair<ll,ll>>& v){
	for(auto ele: v){
		cout << ele.first << " " << ele.second << endl;
	}
	cout << endl;
}

void init(){
	city_pop.clear();
	happ_idx.clear();
	adj_list.clear();
	subtree_size.clear();
	visited.clear();
	people_distrbn.clear();
	parent.clear();
	valid = true;
}

void take_input(){
	scanf("%lld%lld", &num_cities, &num_citizens);
	city_pop.resize(num_cities + 1);
	happ_idx.resize(num_cities + 1);
	adj_list.resize(num_cities + 1);
	subtree_size.resize(num_cities + 1);
	visited.resize(num_cities + 1);
	people_distrbn.resize(num_cities + 1);
	parent.resize(num_cities + 1);
	
	for(int i = 1;i <= num_cities;i++)scanf("%lld",&city_pop[i]);
	for(int i = 1;i <= num_cities;i++)scanf("%lld",&happ_idx[i]);
	for(int i = 0;i < num_cities - 1;i++){
		ll src, dest; scanf("%lld%lld",&src, &dest);
		adj_list[src].insert(dest);
		adj_list[dest].insert(src);
	}
}

void calc_subtree_size(ll node){
	subtree_size[node] = city_pop[node];
	visited[node] = true;
	for(auto nbh: adj_list[node]){
		if(!visited[nbh]){
			calc_subtree_size(nbh);
			subtree_size[node] += subtree_size[nbh];
		} else {
			parent[node] = nbh;
		}
	}
}


void calc_happy_unhappy_people(){
	for(int node = 1;node <= num_cities;node++){
		ll happy_people = (subtree_size[node] + happ_idx[node])/2;
		ll unhappy_people = (subtree_size[node] - happ_idx[node])/2;
		// cout << subtree_size[node] << " " << happ_idx[node] <<  ":" << happy_people << " " << unhappy_people << endl;
		bool no_decimal_numbers = !((happy_people + unhappy_people != subtree_size[node]) || (happy_people - unhappy_people != happ_idx[node]));
		bool positive_people = ((happy_people >= 0) && (unhappy_people >= 0));
		if(!(no_decimal_numbers && positive_people)){
			valid = false;
			return;
		}
		people_distrbn[node] = make_pair(happy_people, unhappy_people);
	}
}

void validate(){
	for(int node = 1; node <= num_cities; node++){
		if(node != 1)adj_list[node].erase(parent[node]);
		ll total_downstream_happy = 0, total_downstream_unhappy = 0;
		for(auto nbh: adj_list[node]){
			total_downstream_happy += people_distrbn[nbh].first;
			total_downstream_unhappy += people_distrbn[nbh].second;
		}

		// cout << "Node: "<< node << " DownHappy:" << total_downstream_happy << " DownUnhappy: " << total_downstream_unhappy << endl;
		
		// more happy people not produced
		bool check1 = (total_downstream_happy <= people_distrbn[node].first);
		
		// ll calc_happ_node = (people_distrbn[node].first - total_downstream_happy), calc_unhapp_node = (people_distrbn[node].second - total_downstream_unhappy);
		// ll calc_node_happ_idx = calc_happ_node - calc_unhapp_node ;
		ll calc_remn_in_node = (people_distrbn[node].first + people_distrbn[node].second) - (total_downstream_happy + total_downstream_unhappy);
		//
		// bool check2 = (calc_node_happ_idx == happ_idx[node]);
		bool check3 = (calc_remn_in_node == city_pop[node]);
		
		if(!(check1 && check3)){
			valid = false;
			return;
		}
	}
}


int main(){
	scanf("%lld", &tests);
	for(int t = 0;t < tests;t++){
		init();
		take_input();
		parent[1] = -1;
		calc_subtree_size(1);
		calc_happy_unhappy_people();
		if(valid) validate();
		if(valid)printf("YES\n");
		else printf("NO\n");
	}


	return 0;
}