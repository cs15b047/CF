#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

vector<ll> prefix_cost_for_black;
ll dp[1001][2]={};
ll n,m,x,y;
ll calc_ans(ll col, ll color){
	if(dp[col][color] != -1)return dp[col][color];
	if(col < x)return (ll)1e18;

	dp[col][color] = 1e18;

	for(int k = x;k <= y; k++){
		if(col >= k){
			ll temp = calc_ans(col - k, 1 - color);
			if(color == 0)temp += (prefix_cost_for_black[col] - prefix_cost_for_black[col - k]) ;
			else temp += k*n - (prefix_cost_for_black[col] - prefix_cost_for_black[col - k]);
			dp[col][color] = min(dp[col][color], temp);
		}
	}
	return dp[col][color];
}

int main(){
	cin >> n >> m >> x >> y;
	vector<string> grid(n);for(int i=0;i<n;i++)cin >> grid[i];
	prefix_cost_for_black.resize(m + 1, 0);
	for(int j=1;j<=m;j++){
		prefix_cost_for_black[j] = prefix_cost_for_black[j-1];
		for(int i = 0;i<n;i++)prefix_cost_for_black[j] += (grid[i][j-1] == '.') ;
	}
	for(int i=0;i<=1000;i++)for(int j=0;j<2;j++)dp[i][j] = -1;
	dp[0][0] = 0;dp[0][1] =0;

	dp[m][0] = calc_ans(m,0);dp[m][1] = calc_ans(m,1);

	cout << min(dp[m][0],dp[m][1]) << endl;

}