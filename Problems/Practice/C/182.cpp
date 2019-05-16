//
#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ifstream  ifile; ofstream  ofile;
	ifile.open("input.txt", ios::in );
	ofile.open("output.txt", ios::out );
	ll n,X; ifile >> n >> X ;
	vector<ll> c(n + 1);for(int i=1;i<=n;i++)ifile >> c[i];
	vector<vector<ll>> dp(n + 1, vector<ll>(X + 1, 0));
	for(ll i=1;i<=n;i++){
		for(ll j =0;j<=X;j++){
			dp[i][j] = dp[i - 1][j];
			ll bud = j + c[i] * (n - i + 1);
			if(bud <= X)dp[i][j] = max(dp[i][j], dp[i - 1][bud] + 1);
		}
	}
	ofile << dp[n][0] << endl;
}