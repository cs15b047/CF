#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll n; scanf("%lld",&n);
	vector<vector<ll>> adj_matrix(n, vector<ll>(n, 0));
	vector<vector<ll>> dp(n, vector<ll>(n, 0));
	for(ll i = 0;i < n;i++){
		for(ll j = 0; j < n; j++){
			cin >> adj_matrix[i][j];
		}
	}
	vector<ll> deletion_order(n);

	for(ll i = 0;i < n;i++){
		cin >> deletion_order[i];
		deletion_order[i]--;
	}
	reverse(deletion_order.begin(), deletion_order.end());

	vector<ll> answer(n, 0);
	set<ll> present;
	present.insert(deletion_order[0]);
	for(ll i = 0;i < n;i++){
		for(ll j = 0;j < n; j++){
			if(i != j){
				dp[i][j] = min(adj_matrix[i][j],adj_matrix[i][deletion_order[0]] + adj_matrix[deletion_order[0]][j]);
			}
		}
	}

	for(ll k = 1; k < n;k++){
		present.insert(deletion_order[k]);
		for(ll i = 0;i <= k;i++){
			for(ll j = 0;j <= k; j++){
				if(deletion_order[i] != deletion_order[j]){
					dp[deletion_order[i]][deletion_order[j]] = min(dp[deletion_order[i]][deletion_order[j]], dp[deletion_order[i]][deletion_order[k]] + dp[deletion_order[k]][deletion_order[j]]);
					answer[k] += dp[deletion_order[i]][deletion_order[j]];
				}
			}
		}
	}

	// for(int k = 0;k < n;k++){
	// 	for(ll i = 0;i < n;i++){
	// 		for(ll j = 0;j < n; j++){
	// 			cout << dp[i][j][0] << " ";
	// 		}
	// 		cout << endl;
	// 	}
	// 	cout << endl;
	// }
	reverse(answer.begin(), answer.end());
	for(ll i = 0;i < n;i++)cout << answer[i] << " ";cout << endl;
}