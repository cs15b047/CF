//#161 D Distance in Tree:
// Q.# of pairs of points in tree with exact k distance bw them
// 1. Root the tree
// dp(node, dist) = # of pts in subtree of node at dist of dist from it
// Ans(u) --> forall Ancestors A, s.t d(u,A) = x, # of v s.t. d(A,v) = k - x, and v is in diff subtree of A than u
// Use dp defn to express above as dp(A, x) - dp(A', x-1), where A' and A are both u's ancestors
#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

ll n, k; 
vector<bool> visited;
vector<set<ll>> adj;
vector<ll> parent;
vector<vector<ll>> dp;

void dfs(ll root){
	visited[root] = 1;
	for(auto nbh:adj[root]){
		if(!visited[nbh]){
			parent[nbh] = root;
			dfs(nbh);
			for(ll dist = 1; dist <= k; dist++){
				dp[root][dist] += dp[nbh][dist - 1];
			}
		}
		else parent[root] = nbh ;
	}
}


int main(){
	cin >> n >> k ;
	visited.clear();visited.resize(n + 1);
	dp.clear();dp.resize(n + 1);for(ll i = 1;i <= n;i++)dp[i].resize(k + 1);

	adj.resize(n + 1);
	parent.resize(n + 1);
	for(ll i = 0; i < n - 1;i++){
		ll s, d; scanf("%lld%lld",&s,&d);
		adj[s].insert(d);adj[d].insert(s);
	}
	
	vector<ll> answer(n + 1);

	parent[1] = -1;
	for(ll i = 1;i <= n;i++)dp[i][0] = 1;
	dfs(1);
	// for(ll i = 1;i <= n;i++){
	// 	for(ll d = 0;d <= k; d++)cout << dp[i][d] << " ";
	// 	cout << endl ;
	// }

	for(ll i = 1;i <= n;i++){
		ll x = 1, node = parent[i], nxt = i ;
		while((x < k) && (node != -1)){
			answer[i] += (dp[node][k - x] - dp[nxt][k - x - 1]) ;
			
			nxt = parent[nxt];	node = parent[node];	x++;
		}
	}
	ll final_answer = 0;
	for(ll i = 1;i <= n;i++)final_answer += answer[i] ;
	final_answer = final_answer / 2;
	for(ll i = 1;i <= n;i++)final_answer += dp[i][k] ;

	cout << final_answer << endl ;
}