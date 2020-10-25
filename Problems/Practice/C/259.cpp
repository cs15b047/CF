#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll mod = 1e9 + 7;

ll num_nodes, num_primes;

vector<set<ll>> adj_list;
vector<ll> primes;
vector<ll> subtree_size, edge_freq;
vector<bool> visited;
vector<pair<ll,ll>> edges;

void init(){
	adj_list.clear();
	primes.clear();
	subtree_size.clear();
	edge_freq.clear();
	visited.clear();
	edges.clear();

	scanf("%lld",&num_nodes);
	
	adj_list.resize(num_nodes + 1);
	subtree_size.resize(num_nodes + 1, 0);
	visited.resize(num_nodes + 1, 0);
	edge_freq.resize(num_nodes - 1, 0);
	edges.resize(num_nodes - 1);
}

void print(vector<ll>& v){
	for(auto ele: v){
		cout << ele << " ";
	}
	cout << endl;
}

void take_input(){
	for(int i = 0;i < num_nodes - 1;i++){
		ll src, dest;
		scanf("%lld%lld",&src, &dest);
		adj_list[src].insert(dest);
		adj_list[dest].insert(src);
		edges[i] = make_pair(src, dest);
	}

	scanf("%lld",&num_primes);
	primes.resize(num_primes);
	for(int i = 0;i < num_primes;i++)scanf("%lld",&primes[i]);
	
	// add remaining as 1 if reqd
	for(int i = 0;i < (num_nodes - 1) - num_primes;i++) primes.push_back(1);

	sort(primes.begin(), primes.end());
}

void calc_subtree_size(ll node){
	subtree_size[node] = 1;
	visited[node] = true;
	for(auto nbh: adj_list[node]){
		if(!visited[nbh]){
			calc_subtree_size(nbh);
			subtree_size[node] += subtree_size[nbh];
		}
	}
}

void calc_edge_freq(){
	for(int i = 0;i < num_nodes - 1;i++){
		pair<ll,ll> edge = edges[i];
		ll child_subtree_size = min(subtree_size[edge.first], subtree_size[edge.second]);
		edge_freq[i] = child_subtree_size * (num_nodes - child_subtree_size);
	}
	sort(edge_freq.begin(), edge_freq.end());
}

ll calc_answer(){
	ll answer = 0;
	// except last, multiply corresponding elements
	for(int i = 0;i < num_nodes - 2;i++){
		answer = (answer + ( ( (edge_freq[i]%mod) * primes[i]) % mod)) % mod;
	}
	ll last_prime_mult = 1;
	for(int i = num_nodes - 2;i < (int)primes.size();i++) last_prime_mult = (last_prime_mult * primes[i]) % mod;
	answer = (answer + ( (edge_freq[num_nodes - 2] % mod) * last_prime_mult) % mod) % mod;
	return answer;
}


int main(){
	ll tests; scanf("%lld",&tests);
	for(int q = 0; q < tests; q++){
		init();
		take_input();
		calc_subtree_size(1);
		calc_edge_freq();
		ll answer = calc_answer();
		cout << answer << endl;
	}


	return 0;
}