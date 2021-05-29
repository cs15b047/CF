#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll num_vertices;
vector<set<ll>> adj_list;
vector<vector<ll>> cost;

vector<ll> degree;
vector<ll> line;
ll start, finish;
vector<ll> final_coloring;

void take_input(){
	scanf("%lld", &num_vertices);
	cost.resize(3, vector<ll>(num_vertices + 1));
	adj_list.clear();
	adj_list.resize(num_vertices + 1);
	degree.resize(num_vertices + 1, 0);
	line.clear();

	for(int i = 0;i < 3;i++){
		for(int j = 1;j <= num_vertices; j++){
			scanf("%lld", &cost[i][j]);
		}
	}

	for(int i = 0;i < num_vertices - 1;i++){
		ll src, dest; scanf("%lld%lld", &src, &dest);
		adj_list[src].insert(dest);
		adj_list[dest].insert(src);
		degree[src]++;
		degree[dest]++;
	}
}

bool validate(){
	start = -1; finish = -1;
	for(ll i = 1; i <= num_vertices; i++){
		if(degree[i] >= 3){
			// cout << "faulty: " << i << endl;
			return false;
		}
		if(degree[i] == 1){
			if(start != -1)finish = i;
			else start = i;
		}
	}
	// cout << "Ends: " << start << " " << finish << endl;
	return true;
}

void make_line(){
	line.push_back(start);
	ll curr = start, nbh = *(adj_list[curr].begin());
	for(int i = 1;i <= num_vertices - 1;i++){
		line.push_back(nbh);
		adj_list[nbh].erase(curr);
		adj_list[curr].erase(nbh);
		if(i != num_vertices - 1){
			curr = nbh;
			nbh = *adj_list[nbh].begin();
		}
	}
	// for(auto it: line)cout << it << " ";cout << endl;
}

ll eval_cost(vector<ll> color){
	ll config_cost = 0;
	for(int i = 0;i < num_vertices; i++){
		config_cost += cost[color[i]][line[i]];
	}
	return config_cost;
}

ll calc_min_cost(){
	ll ans = 1e18;
	// eval for all perms of 3 colors
	for(int i = 0;i < 3;i++){
		for(int j = 0;j < 3;j++){
			if(i == j)continue;

			vector<ll> colors;
			colors.clear(); colors.push_back(i);colors.push_back(j);

			for(int k = 0;k < num_vertices - 2;k++){
				ll sz = colors.size();
				ll val = 3 - (colors[sz - 1] + colors[sz - 2]); // select remaining color
				colors.push_back(val);
			}

			ll config_cost = eval_cost(colors);
			// cout << i << " " <<  j << " " << config_cost << endl;
			if(config_cost < ans){
				ans = config_cost;
				final_coloring = colors;
			}
		}
	}

	// transform coloring according to 1..n from chain order and index colors from 1
	vector<ll> coloring = final_coloring;
	for(int i = 0;i < num_vertices;i++){
		coloring[line[i] - 1] = final_coloring[i] + 1;
	}
	final_coloring = coloring;

	return ans;
}

int main(){
	take_input();
	bool valid = validate();
	if(valid){
		make_line();
		ll ans = calc_min_cost();
		printf("%lld\n", ans);
		for(int i =0;i < num_vertices; i++)printf("%lld ", final_coloring[i]);
		printf("\n");
	} else{
		printf("-1\n");
	}

}