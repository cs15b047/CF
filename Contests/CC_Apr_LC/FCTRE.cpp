#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll mod = 1e9 + 7;

ll n;
vector<ll> is_prime;
vector<ll> primes;

vector<vector<ll>> adj_list;
vector<vector<ll>> children;
vector<ll> arr;

vector<bool> visited;
vector<vector<pair<ll,ll>>> pre, fct_cnt;
vector<set<ll>> subtree;
ll LCA[1001][1001];


void fill_subtrees(ll node){
	visited[node] = true;
	for(auto it: adj_list[node]){
		if(!visited[it]){
			ll sz = pre[it].size();
			auto strt = pre[it].begin();
			auto end = pre[it].begin() + sz;
			for(auto fct: pre[node]){
				auto pos = lower_bound(strt, end, fct.first);
				if(pos != end){
					pos->second += fct.second;
				} else pre[it].push_back(fct);
				// pre[it][fct.first] += fct.second;
			}
			sort(pre[it].begin(), pre[it].end());
			children[node].push_back(it);
			fill_subtrees(it);
			subtree[node].insert(subtree[it].begin(), subtree[it].end());
		}
	}
	subtree[node].insert(node);
	// sort(subtree[node].begin(), subtree[node].end());
}

void assignLCA(ll node){
	for(auto it: children[node]){
		assignLCA(it);
	}
	for(auto ch: children[node]){
		for(auto it: subtree[ch])subtree[node].erase(it);
		for(auto ele1: subtree[ch]){
			for(auto ele2: subtree[node]){
				LCA[ele1][ele2] = node;
				LCA[ele2][ele1] = node;
			}
		}
		for(auto it: subtree[ch])subtree[node].insert(it);
	}
}

void calc_primes(){
	// #########calc primes b/w 1 to 1000########
	is_prime.clear();is_prime.resize(1001, 1);
	primes.clear();
	for(int i = 2;i <= 1000;i++){
		if(is_prime[i]){
			for(int j = i * i;j <= 1000; j += i){
				is_prime[j] = 0;
			}
		}
	}
	for(int i = 2;i <= 1000;i++){
		if(is_prime[i])primes.push_back(i);
	}
	//###########################################
}

vector<pair<ll,ll>> factorize(ll num){
	// cout << "number: " << num << endl;
	vector<pair<ll,ll>> mp; mp.clear();
	for(auto it: primes){
		pair<ll,ll> pr = make_pair(it, 0);
		while(num > 1 && num % it == 0){
			pr.second++;
			num = num / it;
		}
		if(pr.second > 0)mp.push_back(pr);
		if(num == 1)break;
	}
	if(num != 1){
		mp.push_back(make_pair(num, 1));
	}
	// for(auto it: mp)cout << it.first << " " << it.second << endl;
	return mp;
}

ll calc_ans(ll u, ll v, ll lca){
	// factors = pre(u) + pre(v) - 2 * pre(lca) + fct(lca)
	vector<pair<ll,ll>> resultant_arr;
	// ll ptr1
	


	ll ans = 1;
	// cout << fct_cnts.size() << endl;
	// for(auto it: fct_cnts){
	// 	ans = (ans * (it.second + 1)) % mod;
	// }
	return ans;
}

void print_map(map<ll,ll> mp){
	cout << "map strt" << endl;
	for(auto it: mp)cout << it.first << " " << it.second << endl;
	cout << "map over" << endl;
}

int main(){
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	cout << "START!!!!!!" << endl;
	calc_primes(); // from 1 to 1000	
	cout << "primes calculated" << endl;

	ll tests; scanf("%lld",&tests);
	for(int t = 0;t < tests;t++){
		scanf("%lld",&n);
		adj_list.clear();adj_list.resize(n + 1);
		children.clear();children.resize(n + 1);
		subtree.clear();subtree.resize(n + 1);
		// LCA.clear();LCA.resize(n + 1, vector<ll>(n + 1, 0));
		arr.clear();arr.resize(n + 1);
		pre.clear();pre.resize(n + 1);
		fct_cnt.clear();
		visited.clear();visited.resize(n + 1, false);

		// take input
		for(int i = 0; i < n - 1;i++){
			ll src, dest; scanf("%lld%lld",&src, &dest);
			adj_list[src].push_back(dest);
			adj_list[dest].push_back(src);
		}
		for(int i = 1;i <= n;i++)scanf("%lld",&arr[i]);

		// factorize all numbers and calc prefix sum of factor power
		for(int i = 1;i <= n;i++)pre[i] = factorize(arr[i]);
		fct_cnt = pre; // keep individual element fact decomp for use

		ll root = 1;
		// get nodes in subtree of each node
		cout << "Filling subtrees started!!" << endl;
		fill_subtrees(root);
		cout << "Filling subtrees finished!!" << endl;
		// for(int i = 1;i <= n;i++){
		// 	cout << i << ": " << endl;
		// 	for(auto it: children[i])cout << it << " ";cout << endl;
		// }
		// for(int i = 1;i <= n;i++){
		// 	cout << i << ": " << endl;
		// 	for(auto it: pre[i])cout << it.first << " " << it.second << endl;
		// }


		// INit and calculate LCA recursively by dfs
		cout << "LCA compute started!!" << endl;
		for(int i = 1;i <= n;i++)LCA[i][i] = i;
		assignLCA(root);
		cout << "LCA compute finished!!" << endl;


		// cout << "ST: " <<endl;
		// for(int i = 1;i <= n;i++){
		// 	cout << i << ": " << endl;
		// 	for(auto it: subtree[i])cout << it << " ";cout << endl;
		// }
		
		// for(int i = 1;i <= n;i++){
		// 	cout << i << " :"<< endl;
		// 	for(int j = 1;j <= n;j++)cout << LCA[i][j] << " ";cout << endl;
		// }

		// Answer queries using preprocessed data about LCA and factors
		clock_t strt, end;
		strt = clock();
		ll Q; scanf("%lld",&Q);
		vector<ll> answer;
		for(int i =0;i < Q;i++){
			ll u, v; scanf("%lld%lld",&u,&v);
			ll lca = LCA[u][v];
			
			cout << u << " " << v << " " << lca << endl;
			// print_map(pre[u]);print_map(pre[v]);print_map(pre[lca]);
			// exit(0);

			// map<ll,ll> fct_cnts = pre[u];
			// for(auto it: pre[v])fct_cnts[it.first] += it.second;
			// for(auto it: pre[lca]){
			// 	fct_cnts[it.first] -= (2*it.second);
			// 	if(fct_cnts[it.first] == 0)fct_cnts.erase(it.first);
			// }
			// for(auto it: fct_cnt[lca])fct_cnts[it.first] += it.second;
			// ll ans = 1;
			// // cout << fct_cnts.size() << endl;
			// for(auto it: fct_cnts){
			// 	ans = (ans * (it.second + 1)) % mod;
			// }
			// if(i % 5000 == 0)cout << "yo" << endl;

			// ll ans = calc_ans(u, v, lca);
			// answer.push_back(ans);
		}
		end = clock();
		cout << (double)(end - strt)/(double)CLOCKS_PER_SEC << endl;
		strt = clock();
		for(auto it: answer)printf("%lld\n", it);
		end = clock();
		cout << (double)(end - strt)/(double)CLOCKS_PER_SEC << endl;
	}

}