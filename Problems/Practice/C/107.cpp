// B. Longtail Hedgehog #338 - 2
// Dp[i] --> length of longest tail ending at i, and Answer = max over i(Dp[i] x #Nbhs of i)
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<ll>dp;
vector<set<ll>> adj;
ll calc_ans(ll index){
	if(dp[index] != -1)return dp[index];

	dp[index] = 1;
	for(auto nbh:adj[index]){
		if(nbh < index){
			dp[nbh] = calc_ans(nbh);
			if(dp[nbh] + 1 > dp[index]){
				dp[index] = dp[nbh] + 1;
			}
		}
	}
	return dp[index];
}

int main(){
	ll n,m; cin >> n >> m;
	adj.resize(n+1);
	for(int i=0;i<m;i++){
		ll s,d;scanf("%lld%lld",&s,&d);
		adj[s].insert(d);adj[d].insert(s);
	}
	dp.resize(n+1);
	for(int i=1;i<=n;i++)dp[i] = -1;
	for(int i=1;i<=n;i++)dp[i] = calc_ans(i);
	ll answer = 1;
	for(int i=1;i<=n;i++){
		answer = max(answer, dp[i]*(ll)adj[i].size());
	}
	cout << answer << endl ;
}