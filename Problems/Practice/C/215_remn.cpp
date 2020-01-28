#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll k; cin >> k;
	ll n = 100;

	vector<vector<ll>> adj_matrix(n + 1, vector<ll>(n + 1, 0));
	ll curr_edges = 0;
	for(int i = 1;i <= n;i++){
		if(curr_edges == k)break;
		for(int j = i + 1;j <= n; j++){
			if(curr_edges == k)break;
			ll edges_added = 0;
			for(int l = 1;l <= n;l++){
				if(i != l && j != l && adj_matrix[i][l] == 1 && adj_matrix[j][l] == 1){
					edges_added++;
				}
			}
			if(curr_edges + edges_added <= k){
				adj_matrix[i][j] = 1;adj_matrix[j][i] = 1;
				curr_edges += edges_added;
			}
		}
	}
	cout << n << endl;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			cout << adj_matrix[i][j];
		}
		cout << endl;
	}
}