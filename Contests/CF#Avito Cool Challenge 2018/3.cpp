#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll mod = 998244353 ;
ll dp[2001][2001]={};
int main(){
	ll n,m,k; cin >> n >> m >> k ;
	for(int i=1;i<=n;i++)dp[i][0] = m ;

	for(int i=1;i<=n;i++){
		for(int j = 1;j<=k;j++){
			dp[i][j] = (((m - 1)*dp[i-1][j-1]) % mod + dp[i - 1][j]) % mod ;
		}
	}
	cout << dp[n][k] << endl ;
}