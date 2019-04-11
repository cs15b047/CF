#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;
int mod = 1e9 + 7;
int main(){
	int n; cin >> n;
	string prog="";for(int i=0;i<n;i++){string s;cin >> s;prog += s;}

	vector<vector<int>> dp(n, vector<int>(n, 0));

	dp[0][0] = 1;
	vector<int> suffix_sum(n, 0);
	for(int i=1;i<n;i++){
		suffix_sum[n-1] = dp[i-1][n-1];
		for(int k=n-2;k>=0;k--)suffix_sum[k] = (suffix_sum[k + 1] + dp[i-1][k]) % mod;

		for(int j = 0;j<n;j++){
			if(j == 0 && prog[i-1] == 'f')dp[i][j] = 0;
			else if(prog[i - 1] == 'f') dp[i][j] = dp[i - 1][j - 1];
			else if(prog[i-1] == 's') dp[i][j] = suffix_sum[j];
			// cout << i << " " << j << " " << dp[i][j] << endl;
		}
	}
	int answer = 0;
	for(int i=0;i<n;i++){
		answer = (answer + dp[n-1][i]) % mod;
	}
	cout << answer << endl;
}