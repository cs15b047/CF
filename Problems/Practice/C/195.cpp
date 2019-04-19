#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

ll dp[101][101][26]={};
int main(){
	string str;ll k,m;vector<vector<ll>> bonus(26, vector<ll>(26, 0));
	cin >> str >> k >> m;
	ll n = str.length();
	for(int i=0;i<m;i++){string x,y;ll c;cin >> x >> y >> c;bonus[x[0]-'a'][y[0]-'a'] = c;}

	for(int i=0;i<26;i++){
		if(str[0] != ('a' + i))dp[0][0][i] = -1e18;
		// else dp[0][0][i] = 0;
	}
	for(int i = 1;i < n;i++){
		for(int j = 0;j <= k;j++){
			for(int l = 0;l < 26;l++){
				ll ans1 = -1e18, ans2 = -1e18;
				if(str[i] == ('a' + l)){
					for(int p = 0;p < 26;p++){
						ans1 = max(ans1, dp[i - 1][j][p] + bonus[p][l]);
					}
					dp[i][j][l] = ans1;
				}
				else if(j == 0 && str[i] != ('a' + l))dp[i][j][l] = -1e18;
				else{
					for(int p = 0;p < 26;p++){
						ans2 = max(ans2, dp[i - 1][j - 1][p] + bonus[p][l]);
					}
					dp[i][j][l] = ans2;
				}
			}
		}
	}
	ll answer = -1e18;
	for(int p =0;p<26;p++)answer = max(answer, dp[n-1][k][p]);
	cout << answer << endl;
}