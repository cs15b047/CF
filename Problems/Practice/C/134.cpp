#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int dp[5001][5001]={}, prv[5001][5001]={};

vector<set<pair<ll,ll>>> adj;
ll calc_ans(ll node, ll pth_len){
	if(node == 1 && pth_len == 1)return 0;
	if(node == 1 && pth_len > 1)return 1e18;
	if(dp[node][pth_len] != 0)return dp[node][pth_len];

	dp[node][pth_len] = 1e9 + 1 ;
	for(auto nbh:adj[node]){
		ll tmp = calc_ans(nbh.first, pth_len - 1);
		if(dp[node][pth_len] > tmp + nbh.second){
			dp[node][pth_len] = tmp + nbh.second;
			prv[node][pth_len] = nbh.first ;
		}
	}
	return dp[node][pth_len];
}

int main(){
	ll n, m, T; cin >> n >> m >> T ;
	adj.resize(n + 1);
	for(int i=0; i < m; i++){
		ll s, d, w;cin >> d >> s >> w;
		adj[s].insert(make_pair(d, w));
	}

	// for(int i=1;i<=n;i++)for(int j =1;j<=n;j++)dp[i][j] = 0;
	dp[1][1] = 0;

	for(ll i=n;i>=1;i--){
		dp[n][i] = calc_ans(n, i) ;
		if(dp[n][i] <= T){
			cout << i << endl ;
			vector<ll> pth;pth.clear();
			ll curr = n,tmp = i;
			while(curr != 0){
				// cout << curr << endl ;
				pth.push_back(curr);
				curr = prv[curr][tmp];
				tmp--;
			}
			reverse(pth.begin(), pth.end());
			for(auto it:pth)cout << it << " "; cout << endl;
			break;
		}
	}
}