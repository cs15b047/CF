// B. Working out #245 Div 1
// Calculate optimal answers for start pt to some pt and some pt to endpt for both using dp
// Both paths overlap for exactly 1 cell, not more, so for the meeting cell direction of approach and leaving will be constrained
#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

ll grid[1001][1001]={}, dp1[1001][1001]={},dp2[1001][1001]={},dp3[1001][1001]={},dp4[1001][1001]={};
ll n, m;

ll c1(ll row, ll col){
	if(dp1[row][col] != -1)return dp1[row][col];
	if(row == 1)dp1[row][col] = c1(row, col - 1) + grid[row][col];
	else if(col == 1)dp1[row][col] = c1(row - 1, col) + grid[row][col];
	else dp1[row][col] = max(c1(row - 1, col), c1(row, col - 1)) + grid[row][col];

	return dp1[row][col];
}
ll c2(ll row, ll col){
	if(dp2[row][col] != -1)return dp2[row][col];
	if(row == n)dp2[row][col] = c2(row, col + 1) + grid[row][col];
	else if(col == m)dp2[row][col] = c2(row + 1, col) + grid[row][col];
	else dp2[row][col] = max(c2(row + 1, col), c2(row, col + 1)) + grid[row][col];
	return dp2[row][col];
}

ll c3(ll row, ll col){
	if(dp3[row][col] != -1)return dp3[row][col];
	if(row == n)dp3[row][col] = c3(row, col - 1) + grid[row][col];
	else if(col == 1)dp3[row][col] = c3(row + 1, col) + grid[row][col];
	else dp3[row][col] = max(c3(row + 1, col), c3(row, col - 1)) + grid[row][col];

	return dp3[row][col];
}
ll c4(ll row, ll col){
	if(dp4[row][col] != -1)return dp4[row][col];
	if(row == 1)dp4[row][col] = c4(row, col + 1) + grid[row][col];
	else if(col == m)dp4[row][col] = c4(row - 1, col) + grid[row][col];
	else dp4[row][col] = max(c4(row - 1, col), c4(row, col + 1)) + grid[row][col];

	return dp4[row][col];
}


int main(){
	scanf("%lld%lld",&n,&m);

	for(ll i = 1;i <= n ;i++)for(ll j = 1;j <= m ;j++)scanf("%lld",&grid[i][j]);
	for(ll i = 1;i <= n ;i++){
		for(ll j = 1;j <= m ;j++){
			dp1[i][j] = -1;dp2[i][j] = -1;dp3[i][j] = -1;dp4[i][j] = -1;
		}
	}
	dp1[1][1] = grid[1][1];
	dp2[n][m] = grid[n][m];
	dp3[n][1] = grid[n][1];
	dp4[1][m] = grid[1][m];

	ll a1 = c1(n, m), a2 = c2(1, 1), a3 = c3(1, m), a4 = c4(n, 1);

	ll final_answer = 0;
	for(ll i = 2;i <= n - 1 ;i++){
		for(ll j = 2;j <= m - 1 ;j++){
			ll intmdt = max(dp1[i - 1][j] + dp2[i + 1][j] + dp3[i][j - 1] + dp4[i][j + 1], 
				dp1[i][j - 1] + dp2[i][j + 1] + dp3[i + 1][j] + dp4[i - 1][j]);
			final_answer = max(final_answer, intmdt);
		}
	}
	printf("%lld\n",final_answer );

}