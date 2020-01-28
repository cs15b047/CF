// Do topological sort and store free nodes in different buckets
// In Top sort, get all possible nodes into bucket before switching bucket
// Can Switch in order 1-2-3-1-2-3.... Costs make all movements >= cost than this

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<set<ll>> adj_list; 
vector<ll> computer_numbers;

ll calc_cost(ll num_parts, vector<ll> indegree, ll curr_computer_num){
	vector<set<ll>> numberwise_free_nodes(4);
	for(int i = 1;i <= num_parts;i++){
		if(indegree[i] == 0)
			numberwise_free_nodes[computer_numbers[i]].insert(i);
	}
	ll processed_nodes = 0;
	ll cost = 0;

	while(processed_nodes < num_parts){
		while(!numberwise_free_nodes[curr_computer_num].empty()){
			ll top = *numberwise_free_nodes[curr_computer_num].begin();
			// cout << top << " ";
			processed_nodes++;
			numberwise_free_nodes[curr_computer_num].erase(top);

			for(auto nbh: adj_list[top]){
				ll comp_num = computer_numbers[nbh];
				indegree[nbh]--;
				if(indegree[nbh] == 0)
					numberwise_free_nodes[comp_num].insert(nbh);
			}
		}
		// cout << "yippee" << endl;
		if(processed_nodes < num_parts){
			curr_computer_num = (curr_computer_num % 3) + 1;
			cost++;
		} else{
			break;
		}
	}
	// cout << endl;
	return cost;
}

int main(){
	ll num_parts; cin >> num_parts;
	computer_numbers.resize(num_parts + 1, 0);
	for(int i = 1;i <= num_parts; i++)cin >> computer_numbers[i];
	adj_list.resize(num_parts + 1);
	vector<ll> indegree; indegree.resize(num_parts + 1, 0);
	for(int i = 1;i <= num_parts;i++){
		ll num_nbh; cin >> num_nbh;
		for(int j = 0;j < num_nbh;j++){
			ll nbh; cin >> nbh;
			adj_list[nbh].insert(i);
			indegree[i]++;
		}
	}
	// for(int i = 1; i <=  num_parts; i++){
	// 	cout << i << ": ";
	// 	for(auto it: adj_list[i])cout << it << " ";cout << endl;
	// }
	ll answer = 1e18;
	for(ll curr_computer_num = 1; curr_computer_num <= 3;curr_computer_num++){
		ll cost = calc_cost(num_parts, indegree, curr_computer_num);
		// cout << curr_computer_num << " " << cost << endl;
		answer = min(answer, cost);
	}
	cout << answer + num_parts << endl;
}