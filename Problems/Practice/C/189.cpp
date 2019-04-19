#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll n,m,k; scanf("%lld%lld%lld",&n,&m,&k);
	vector<string> grid(n);for(int i=0;i<n;i++){char s[501];scanf("%s",s);string str(s);grid[i] = str;}
	vector<vector<ll>> posns(n);
	for(int i=0;i<n;i++){
		posns[i].clear();
		for(int j = 0;j < m;j++){
			if(grid[i][j] == '1')posns[i].push_back(j);
		}
	}
	vector<vector<ll>> Time(n, vector<ll>(k + 1, 1e18));
	for(int i=0;i<n;i++){
		if(!posns[i].empty())Time[i][0] = posns[i].back() - posns[i][0] + 1;
		else Time[i][0] = 0;
		for(int j = 1;j <= k;j++){
			if(j >= posns[i].size())Time[i][j] = 0;
			else{
				ll sz = posns[i].size();
				for(int l = 0;l <= j;l++){
					Time[i][j] = min(Time[i][j], posns[i][sz - j + l - 1] - posns[i][l] + 1);
				}
			}
		}
	}
	vector<vector<ll>> dp(n, vector<ll>(k + 1, 1e18));
	for(int b = 0;b <=k;b++)dp[0][b] = Time[0][b];
	for(int i=1;i<n;i++){
		for(int b = 0;b <= k; b++){
			ll ans = 1e18;
			for(int j = 0;j <= b;j++)ans = min(ans, dp[i - 1][b - j] + Time[i][j]);
			dp[i][b] = ans;
		}
	}	
	cout << dp[n - 1][k] << endl;
}