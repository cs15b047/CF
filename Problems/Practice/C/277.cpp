#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll num_vtx;
vector<ll> vtx_value;

vector<ll> values;
vector<vector<int>> bit_reprs;

vector<set<ll>> adj_list;

ll SZ = 61;

void remove_zeros(){
	vtx_value.clear();
	for(auto it: values){
		if(it != 0) vtx_value.push_back(it);
	}
	num_vtx = vtx_value.size();
}

void initialize(){
	scanf("%lld", &num_vtx);
	values.resize(num_vtx);
	for(int i = 0;i < num_vtx;i++)scanf("%lld", &values[i]);
	remove_zeros();
	bit_reprs.resize(num_vtx);
	adj_list.resize(num_vtx);
}

vector<int> convert_to_bit_repr(ll number){
	vector<int> repr(SZ, 0);
	for(int i = 0;i < SZ && number > 0;i++){
		repr[i] = number % 2 ;
		number = number / 2;
	}
	return repr;
}

void print_bit_repr(ll num){
	vector<int> repr = convert_to_bit_repr(num);
	for(auto it: repr){
		cout << it;
	}
	cout << endl;
}

void populate_bit_reprs(){
	for(int i = 0;i < num_vtx; i++){
		bit_reprs[i] = convert_to_bit_repr(vtx_value[i]);
		// print_bit_repr(vtx_value[i]);
	}
}

void print_graph(){
	cout << "Adj list: " << endl;
	for(int i = 0;i < num_vtx; i++){
		cout <<" vtx: " << i << " ";
		for(auto it: adj_list[i])cout << it << " ";
		cout << endl;
	}
}

// At max 3 * SZ - 1 numbers can be present if clique is not to be formed: Pigeonhole
bool check_clique_presence_by_bit_grouping(){
	for(int i = 0; i < SZ; i++){
		ll nums_with_bit_set = 0;
		for(int j = 0;j < num_vtx; j++){
			nums_with_bit_set += bit_reprs[j][i];
			if(nums_with_bit_set >= 3){
				// cout << "More than 3 bits set on position: " << i << endl;
				return true;
			}
		}
		// cout << "position " << i << " : Bits set: " << nums_with_bit_set << endl;
	}
	return false;
}

// can brute force as max # of vtx <= 3 * SZ
void form_graph(){
	for(int i = 0; i < num_vtx; i++){
		adj_list[i].clear();
		for(int j = 0;j < num_vtx; j++){
			if(i == j)continue;
			if((vtx_value[i] & vtx_value[j]) != 0){
				adj_list[i].insert(j);
			}
		}
	}
	// print_graph();
}

ll ans_containing_vtx(ll node){
	vector<bool> visited(num_vtx, false);
	vector<ll> dist(num_vtx, 0);
	vector<ll> parent(num_vtx, -1);

	// do bfs from node and check for cycles while iterating
	queue<ll> q;
	visited[node] = true;
	dist[node] = 0;
	q.push(node);
	parent[node] = -1;

	ll ans = 1e9;

	while(!q.empty()){
		ll top = q.front(); q.pop();
		// cout << top << " ";
		for(auto it: adj_list[top]){
			if(!visited[it]){
				parent[it] = top;
				visited[it] = true;
				dist[it] = dist[top] + 1;
				q.push(it);
			} else if(it != parent[top]){
				ans = min(ans, dist[it] + dist[top] + 1);
			}
		}
	}

	// bfs stats:

	// cout << "Parents:" <<endl;
	// for(auto it: parent)cout << it << " ";cout << endl;
	// cout << "Dist:" <<endl;
	// for(auto it: dist)cout << it << " ";cout << endl;


	// cout << "Vtx: " << node << " : " << "Answer: " << ans << endl;
	visited.clear(); dist.clear(); parent.clear();

	return ans;
}

ll calc_ans(){
	ll ans = 1e9;
	for(ll i = 0;i < num_vtx; i++){
		ll itr_ans = ans_containing_vtx(i);
		ans = min(ans, itr_ans);
	}
	if(ans == 1e9)ans = -1;
	return ans;
}

int main(){
	initialize();
	populate_bit_reprs();
	bool clique_present = check_clique_presence_by_bit_grouping();
	if(clique_present)printf("3\n");
	else{
		ll answer;
		form_graph();
		answer = calc_ans();
		printf("%lld\n", answer);
	}
}