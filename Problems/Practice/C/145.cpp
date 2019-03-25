// B. MADMAX #459 -div 1
// dp[player][posA][posB][constraint] = Winner of game starting from players being at posA, posB with turn of "player" with letter constraint
#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

vector<set<pair<ll,ll>>> adj;
ll dp[2][101][101][26] = {};

ll calc_ans(ll index_A, ll index_B, ll constraint, ll player){
	if(dp[player][index_A][index_B][constraint] != -1)return dp[player][index_A][index_B][constraint];
	ll node_ans = 1 - player;
	if(player == 1){
		for(auto nbh: adj[index_A]){
			if(nbh.second >= constraint)
				node_ans = max(node_ans, calc_ans(nbh.first, index_B, nbh.second, 1 - player));
		}
	}
	else{
		for(auto nbh: adj[index_B]){
			if(nbh.second >= constraint){
				node_ans = min(node_ans, calc_ans(index_A, nbh.first, nbh.second, 1 - player));
			}
		}
	}
	dp[player][index_A][index_B][constraint] = node_ans;
	return node_ans;
}


int main(){
	ll n, m; scanf("%lld%lld",&n,&m);

	adj.resize(n + 1);
	for(ll i = 0;i < m ;i++){
		ll s,d; char wt[2];
		scanf("%lld%lld%s",&s,&d,wt);
		adj[s].insert(make_pair(d, (ll)(wt[0] - 'a'))); // char - char ???
	}
	for(ll x =0;x<2;x++){
		for(ll i = 1;i<=n;i++){
			for(ll j = 1;j<=n;j++){
				for(ll wt = 0;wt < 26;wt++){
					dp[x][i][j][wt] = -1;
				}
			}
		}
	}


	vector<vector<ll>> answer(n + 1, vector<ll>(n + 1));
	for(ll i = 1;i <= n; i++){
		for(ll j = 1;j<=n;j++){
			answer[i][j] = calc_ans(i, j, 0, 1);
			if(answer[i][j] == 1)cout <<"A";
			else cout <<"B";
		}
		cout <<endl;
	}
}