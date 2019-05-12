#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	string str; cin >> str;
	ll n = str.length();
	vector<ll> orig(n);for(int i=0;i<n;i++)orig[i] = (str[i] - '0');
	vector<vector<ll>> dp(n, vector<ll>(10, 0));
	for(int i=0;i<=9;i++)dp[0][i] = 1;

	for(int i=1;i<n;i++){
		for(int j=0;j<=9;j++){
			for(int k = 0;k <= 9; k++){
				if(((k + orig[i])/2 == j) || ( (int)ceil((double)(k + orig[i])/(double)2) == j) ) {
					dp[i][j] += dp[i - 1][k];
				}
			}
		}
	}
	ll answer = 0;
	for(int i=0;i<=9;i++)answer += dp[n - 1][i];

	vector<ll> dup = orig;
	int flag = 1;
	for(int i=1;i<n;i++){
		if(((dup[i - 1] + orig[i])/2 == dup[i]) || ( (int)ceil((double)(dup[i - 1] + orig[i])/(double)2) == dup[i]) )continue;
		else {flag = 0;break;}
	}
	cout << answer - flag << endl;

}