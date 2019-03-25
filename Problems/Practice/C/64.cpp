#include <bits/stdc++.h>
using namespace std ;

typedef long long int ll ;
int dp[501][501][2];
int main(){
	ll n,m,b,mod;cin>>n>>m>>b>>mod;
	vector<ll> a(n);for(int i=0;i<n;i++)scanf("%lld",&a[i]);

	for(int i=1;i<=m;i++)
		for(int j=0;j<=b;j++)
			dp[i][j][0] = 0;

	for(int j=0;j<=b;j++)
		dp[0][j][0] = 1;
	
	for(int k=1;k<=n;k++){
		for(int j=0;j<=b;j++)
			dp[0][j][k%2] = 1;
		for(int i=1;i<=m;i++){
			for(int j=0;j<=b;j++){
				dp[i][j][k%2] = dp[i][j][(k-1)%2] ;
				if((j >= a[k-1]))dp[i][j][k%2] = (dp[i][j][(k-1)%2] + dp[i-1][j-a[k-1]][k%2]) % mod ;
			}
		}
	}

	cout << dp[m][b][n%2] << endl ;



}