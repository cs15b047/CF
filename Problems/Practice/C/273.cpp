#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll num_lvls;
vector<vector<ll>> temp_ans;
vector<ll> answer;

ll max_lvls = 2000000, mod = 1e9 + 7;

void preprocess(){
	temp_ans.resize(max_lvls + 1, vector<ll>(2, 0));
	answer.resize(max_lvls + 1, 0);

	for(int i = 3; i <= max_lvls; i++){
		temp_ans[i][0] = (2 * answer[i - 2] + answer[i - 1]) % mod;
		temp_ans[i][1] = (4 + temp_ans[i - 1][0] + 2 * temp_ans[i - 2][0]) % mod;
		answer[i] = max(temp_ans[i][0], temp_ans[i][1]);
	}
}

void initialize(){
	scanf("%lld", &num_lvls);
}

int main(){
	ll tests; scanf("%lld", &tests);
	preprocess();
	for(int i = 0;i < tests;i++){
		initialize();
		printf("%lld\n", answer[num_lvls]);
	}
}