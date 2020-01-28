#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<ll> a,b,c;
vector<ll> parent;
vector<vector<ll>> adj;

bool cmp(ll x, ll y){
	return c[x] > c[y];
}

void create_graph(ll m, ll n){
	// Only keep highest index parent
	for(int i=0;i<m;i++){
		ll s,d;scanf("%lld%lld",&s,&d);
		if(parent[d] < s)parent[d] = s;
	}

	// prepare outgoing edges, for no edges: self loop
	for(int i = 1;i <= n;i++){
		if(parent[i] != 0){
			adj[parent[i]].push_back(i);
		} else{
			parent[i] = i;
			adj[i].push_back(i);
		}
	}

	// sort edges in order of profit
	for(int i = 1;i <=n;i++){
		sort(adj[i].begin(), adj[i].end(), cmp);
	}
}

bool check(ll n, ll k, vector<ll> sent_warriors){
	ll curr_warriors = k;
	if(k < a[1])return false;
	curr_warriors = k + b[1] - sent_warriors[1];
	for(int i = 2;i <= n;i++){
		// curr + prev addn - sent from prev = new_curr
		if(curr_warriors < a[i])
			return false;
		curr_warriors += b[i] - sent_warriors[i];
	}
	// end of castles condition
	if(curr_warriors < 0)return false;
	return true;
}

ll calc_ans(ll n, ll m, ll k){
	vector<ll> indices(n);
	for(int i = 1;i <= n;i++)indices[i-1] = i;
	sort(indices.begin(), indices.end(), cmp);
	// for(auto it: indices)cout << it << " ";cout<< endl;

	vector<ll> sent_warriors;
	sent_warriors.resize(n + 1, 0);

	ll total = 0;

	for(int i = 0;i < n;i++){
		ll node = indices[i], parent_node = parent[node];

		sent_warriors[parent_node]++;
		bool possible = check(n, k, sent_warriors);
		if(!possible)sent_warriors[parent_node]--;
		else{
			total += c[indices[i]];
			// cout << "Defended: " << indices[i] << endl;
		}
	}
	return total;
}

int main(){
	ll n, m, k; cin >> n >> m >> k;
	a.resize(n + 1); b.resize(n + 1);c.resize(n + 1);
	parent.resize(n + 1, 0);
	adj.resize(n + 1);

	for(int i =1;i<=n;i++){
		scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
	}
	create_graph(m, n);
	vector<ll> sent_warriors(n + 1, 0);
	bool possible = check(n, k, sent_warriors);
	if(!possible){
		cout << - 1 << endl;
	} else{
		ll answer = calc_ans(n, m, k);
		cout << answer << endl;
	}

}