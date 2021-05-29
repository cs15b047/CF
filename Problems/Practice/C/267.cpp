#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll len1, len2;
string str1, str2;
vector<vector<ll>> dp;

void take_input(){
	char s1[5100], s2[5100];
	scanf("%lld%lld",&len1, &len2);
	scanf("%s%s", s1, s2);
	string st1(s1), st2(s2);
	str1 = st1; str2 = st2;
	dp.resize(len1 + 1, vector<ll>(len2 + 1, 0));
}

ll calc_ans(){
	// for(int i = 1;i <= len1; i++) dp[i][0] = -i;
	// for(int i = 1;i <= len2; i++) dp[0][i] = -i;

	ll ans = 0;

	for(int i = 1;i <= len1; i++){
		for(int j = 1;j <= len2; j++){
			if(str1[i - 1] == str2[j - 1]){
				dp[i][j] = max((ll)0, dp[i - 1][j - 1] + 2);
			} else{
				dp[i][j] = max((ll)0, max(dp[i - 1][j], dp[i][j - 1]) - 1);
			}
			ans = max(ans, dp[i][j]);
		}
	}
	// for(int i = 0;i <= len1; i++){
	// 	for(int j = 0;j <= len2; j++){
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	return ans;
}

int main(){
	take_input();
	ll ans = calc_ans();
	printf("%lld\n", ans);
}