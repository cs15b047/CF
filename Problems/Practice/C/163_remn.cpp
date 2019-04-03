#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

vector<ll> thickness, width;
ll dp[101][201][201]={};

int main(){
	ll n; scanf("%lld",&n);
	thickness.resize(n+1);width.resize(n+1);
	for(int i=1;i<=n;i++)cin >> thickness[i] >> width[i] ;
	
	dp[0][0][0] = 1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=200;j++){
			for(int k=0;k<=200;k++){
				if(j >= thickness[i])dp[i][j][k] = dp[i - 1][j - thickness[i]][k];
				if(k >= width[i])dp[i][j][k] = dp[i][j][k] + dp[i-1][j][k - width[i]] ;
			}
		}
	}

	ll answer=-1;
	for(int j=1;j<=200;j++){
		for(int k=0;k<=j;k++){
			if(dp[n][j][k] > 0){
				answer = j;
				break;
			}
		}
		if(answer != -1)break;
	}
	cout << answer << endl;
}