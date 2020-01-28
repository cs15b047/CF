#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	string string1, string2;cin >> string1 >> string2;
	ll num_edges; cin >> num_edges;
	ll num_char = 27;
	vector<vector<ll>> adj_matrix(num_char, vector<ll>(num_char,1e9));
	vector<ll> shortest_dist(num_char, 1e9);
	for(int i = 0;i < num_edges;i++){
		string c1, c2;cin >> c1 >> c2;
		ll wt; cin >> wt;
		
		// counter multi - edges by taking min
		adj_matrix[(c1[0] - 'a') + 1][(c2[0] - 'a') + 1] = min(wt, adj_matrix[(c1[0] - 'a') + 1][(c2[0] - 'a') + 1]);
	}
	// dist with self : 0
	for(int i = 1; i <= 26;i++)adj_matrix[i][i] = 0;
	
	// floyd warshall
	// init
	vector<vector<ll>> dp(num_char, vector<ll>(num_char, 1e9));
	for(int i = 1; i <= 26;i++){
		for(int j = 1; j <= 26;j++){
			dp[i][j] = adj_matrix[i][j];
		}
	}
	// algo
	for(int k = 1;k <= 26; k++){
		for(int i = 1; i <= 26;i++){
			for(int j = 1; j <= 26;j++){
				dp[i][j] = min(dp[i][k] + dp[k][j], dp[i][j]);
			}
		}
	}

	if(string1.length() != string2.length()){
		cout << -1 << endl;
	} else{
		ll len = string1.length();
		string str = "";for(int i = 0;i < len;i++)str += 'a';
		ll ans = 0;
		for(int i = 0;i < len;i++){
			char c1 = string1[i], c2 = string2[i];
			ll dist = 1e9;
			ll opt = -1;

			// choose optimum char at a position
			for(int k = 1;k <= 26;k++){
				if(dist > dp[(c1 - 'a') + 1][k] + dp[(c2 - 'a') + 1][k]){
					dist = dp[(c1 - 'a') + 1][k] + dp[(c2 - 'a') + 1][k];
					opt = k;
				}
			}
			// for higher dist : not poss
			if(dist >= 1e9){
				ans = -1;
				break;
			} else{
				// modify string
				ans += dist;
				str[i] += (opt - 1); 
			}
		}
		cout << ans << endl;
		if(ans != -1)cout << str << endl;
	}
}