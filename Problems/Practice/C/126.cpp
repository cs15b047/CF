//B. Arpa's weak amphitheater and Mehrdad's valuable Hoses - #383 - 1
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

map<ll,bool> visited;
vector<set<ll>> components;
vector<set<ll>> adj;
void dfs(ll node){
	visited[node] = 1;
	components.back().insert(node);
	for(auto nbh:adj[node]){
		if(visited.find(nbh) == visited.end()){
			dfs(nbh);
		}
	}
}


int main(){
	ll n, m, W; cin >> n >> m >> W;visited.clear();components.clear();adj.clear();
	vector<ll>w(n+1),b(n+1);for(int i=1;i<=n;i++)cin >> w[i] ;for(int i=1;i<=n;i++)cin >> b[i] ;
	adj.resize(n+1);for(int i=0;i<m;i++){ll s,d; cin >> s >> d ;adj[s].insert(d);adj[d].insert(s);}

	set<ll> emty;emty.clear();
	components.push_back(emty);
	for(int i=1;i<=n;i++){
		if(visited.find(i) == visited.end()){
			components.push_back(emty);
			dfs(i);
		}
	}
	ll C = components.size() - 1;
	vector<vector<ll>> dp(C + 1);for(int i=0;i<=C;i++)dp[i].resize(W+1);
	// for(int i=0;i<=C;i++)dp[i][0] = 0;

	vector<ll>combined_w(C+1), combined_b(C+1);
	for(int i=1;i<=C;i++){
		combined_w[i] =0; combined_b[i] = 0;
		for(auto pt:components[i]){
			combined_w[i] += w[pt];
			combined_b[i] += b[pt];
		}
	}

	// for(int i=1;i<=C;i++){
	// 	for(auto it:components[i])cout << it << " ";cout <<endl;
	// }


	for(int i=1;i<=C;i++){
		for(int j = 1;j <= W;j++){
			dp[i][j] = 0;
			if(j >= combined_w[i])dp[i][j] = max(dp[i][j], dp[i - 1][j - combined_w[i]] + combined_b[i]) ;
			for(auto pt:components[i]){
				if(j >= w[pt])dp[i][j] = max(dp[i][j], dp[i - 1][j - w[pt]] + b[pt]) ;
			}
			dp[i][j] = max(dp[i][j], dp[i-1][j]) ;
		}
	}
	cout << dp[C][W] << endl;
}