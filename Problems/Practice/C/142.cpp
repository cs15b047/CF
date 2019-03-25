// D. Caesar's Legions  --> Beta round #89 - div 2
// dp[n1][n2][c1][c2] = # arrangements for n1 and n2 of each kind with c1 of type 1 and c2 of type 2 at the end.(1 of c1 and c2 will be 0).
//Take care at ending when c1 = k1 or c2 = k2, by switchover to other type.
#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

ll mod = 1e8;
ll k1,k2;

ll dp[101][101][11][11]={};

ll calc_ans(ll n1, ll n2, ll c1, ll c2){
	// cout << n1 << " " << n2 << " " << c1 << " " << c2 << endl;
	if(dp[n1][n2][c1][c2] != -1)return dp[n1][n2][c1][c2];
	if(n1 == 0 && n2 <= k2)return 1;
	if(n1 == 0 && n2 > k2)return 0;
	if(n2 == 0 && n1 > k1)return 0;
	if(n2 == 0 && n1 <= k1)return 1;

	dp[n1][n2][c1][c2] = 0;
	ll answer = 0;
	if(c1 == k1){
		answer  = (answer + calc_ans(n1, n2 - 1, 0, 1)) % mod;
	}
	else if(c2 == k2){
		answer  = (answer + calc_ans(n1 - 1, n2, 1, 0)) % mod;
	}
	else{
		answer = (answer + calc_ans(n1 - 1, n2, c1 + 1, 0)) % mod;
		answer = (answer + calc_ans(n1, n2 - 1, 0, c2 + 1)) % mod;
	}
	dp[n1][n2][c1][c2] = answer ;

	return dp[n1][n2][c1][c2];
}

int main(){
	ll n1, n2;cin >> n1 >> n2 >> k1 >> k2;

	for(ll i=0;i<=n1;i++){
		for(ll j=0;j<=n2;j++){
			for(ll k=0;k<=10;k++){
				for(ll l=0;l<=10;l++)
					dp[i][j][k][l] = -1;
			}
		}
	}
	for(ll k=0;k<=k1;k++){
		for(ll l=0;l<=k2;l++)
				dp[0][0][k][l] = 1;
	}


	ll answer = calc_ans(n1, n2, 0, 0);
	cout << answer << endl;



}