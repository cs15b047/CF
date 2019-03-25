#include <bits/stdc++.h>
using namespace std ;

typedef long long int ll ;
int dp[31001][501];
int cnts[30001]={};
ll inv=0,o_d;

ll solve(ll n, ll d){
	if(n > 30000)return 0;
	if(dp[n][250+d] != -1)return dp[n][250+d];
	inv++;
	ll act_d = d + o_d ;
	if(act_d==1){
		ll p2 = solve(n+act_d,d);ll p3 = solve(n+act_d+1,d+1);
		if(n+act_d <= 30000)dp[n+act_d][250+d] = p2;
		if(n+act_d+1 <= 30000)dp[n+act_d+1][250+d+1] = p3;
		dp[n][250+d] = max(p2, p3) + cnts[n];
	}
	else{
		ll p1 =solve(n+act_d-1,d-1);ll p2 = solve(n+act_d,d);ll p3 = solve(n+act_d+1,d+1);
		if(n+act_d-1 <= 30000)dp[n+act_d-1][250+d-1] = p1;
		if(n+act_d <= 30000)dp[n+act_d][250+d] = p2;
		if(n+act_d+1 <= 30000)dp[n+act_d+1][250+d+1] = p3;
		dp[n][250+d] = max(p1,max(p2,p3)) + cnts[n] ;
	} 
	return dp[n][250+d];
}

int main(){
	ll n;cin>>n>>o_d;
	for(int i=1;i<=n;i++){
		ll x;cin>>x;
		cnts[x]++;
	}

	for(int i=1;i<=30000;i++)
		for(int j=1;j<=500;j++)
			dp[i][j] = -1 ;

	ll ans = solve(o_d,0);
	cout << ans << endl ;
	// cout << inv << endl ;

}