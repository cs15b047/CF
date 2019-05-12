#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

ll mod = 1e9+7;
ll dp[3001][101][2]={};
ll n, len;
ll calc_ans(ll leng, ll ending, ll orient, vector<vector<ll>> &length, vector<vector<ll>> &width){
	if(leng < length[ending][orient])return 0;
	if(dp[leng][ending][orient] != -1)return dp[leng][ending][orient];
	ll tmp_ans = 0;
	for(int i=0;i<n;i++){
		if(i != ending){
			if(length[ending][orient] == width[i][0]){
				tmp_ans = (tmp_ans + calc_ans(leng - length[ending][orient], i, 0, length, width)) % mod;
			}
			else if(length[ending][orient] == width[i][1]){
				tmp_ans = (tmp_ans + calc_ans(leng - length[ending][orient], i, 1, length, width)) % mod;
			}
		}
	}
	dp[leng][ending][orient] = tmp_ans;
	return tmp_ans;
}

int main(){
	cin >> n >> len;
	vector<vector<ll>> length(n, vector<ll>(2,0)), width(n, vector<ll>(2,0));
	for(int i=0;i<n;i++)cin >> length[i][0] >> width[i][0];
	for(int i=0;i<n;i++){width[i][1] = length[i][0]; length[i][1] = width[i][0];}

	for(int i=0;i<=len;i++){
		for(int j=0;j<n;j++){
			dp[i][j][0] = -1;dp[i][j][1] = -1;
		}
	}
	for(int i=0;i<n;i++){
		dp[length[i][0]][i][0] = 1;
		if(length[i][0] != width[i][0])dp[width[i][0]][i][1] = 1;
		else dp[width[i][0]][i][1] = 0;
	}
	ll answer = 0;
	for(int i=0;i<n;i++){
		ll ans1 = calc_ans(len, i, 0, length, width);
		ll ans2 = calc_ans(len, i, 1, length, width);
		answer = (answer + (ans1 + ans2 * (length[i][0] != width[i][0])) % mod) % mod;
	}
	cout << answer << endl;

}