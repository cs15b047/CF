#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod = 998244353;
int main()
{
	ll n,k;cin>>n>>k;
	vector<vector<vector<ll>>> dp(n+1);
	for(int i=0;i<=n;i++)dp[i].resize(2*n+1);
	for(int i=0;i<=n;i++){
		for(int j=0;j<=k;j++){
			dp[i][j].resize(5) ;
		}
	}
	dp[0][0][1] = 1;dp[0][0][2] = 1;dp[0][0][3] = 1;dp[0][0][4] = 1;
	for(int i=1;i<=n;i++){
		for(int l=1;l<=4;l++)
			dp[i][0][l] = 0;
	}
	for(int i=1;i<=k;i++){
		for(int l=1;l<=4;l++)
			dp[0][i][l] = 0;
	}

	for(int i=1;i<=n;i++){
		for(int l=1;l<=2;l++)
			dp[i][1][l] = 1 ;
	}
	for(int i=1;i<=n;i++){
		for(int l=3;l<=4;l++)
			dp[i][1][l] = 0 ;
	}

	if(k>=2)for(int l=3;l<=4;l++)dp[1][2][l]=1;

	if(n==1){cout << (dp[n][k][1] + dp[n][k][2] + dp[n][k][3] + dp[n][k][4])%mod << endl;exit(0);}
	if(k==1){cout << (dp[n][k][1] + dp[n][k][2] + dp[n][k][3] + dp[n][k][4])%mod << endl;exit(0);}

	for(int i=1;i<=n;i++){
		for(int j=2;j<=k;j++){
			dp[i][j][1] = (dp[i-1][j][1] + dp[i-1][j-1][2] + dp[i-1][j][3] + dp[i-1][j][4]) % mod ;
			dp[i][j][2] = (dp[i-1][j][2] + dp[i-1][j-1][1] + dp[i-1][j][3] + dp[i-1][j][4]) % mod ;
			dp[i][j][3] = (dp[i-1][j][3] + dp[i-1][j-2][4] + dp[i-1][j-1][1] + dp[i-1][j-1][2]) % mod ;
			dp[i][j][4] = (dp[i-1][j][4] + dp[i-1][j-2][3] + dp[i-1][j-1][1] + dp[i-1][j-1][2])% mod ;
		}
	}
	cout << (dp[n][k][1] + dp[n][k][2]+dp[n][k][3] + dp[n][k][4]) % mod << endl ;
	
	return 0;
}