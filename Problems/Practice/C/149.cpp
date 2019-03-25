//B. Solitaire #130 -2
// dp(state) = 1 if state can result in winning (finishing deck), else 0 
#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

map<vector<string>, bool> dp;

bool calc_ans(vector<string> state){
	if(dp.find(state) != dp.end())return dp[state];
	if(state.size() == 1)return true;
	string last = state.back();
	bool ans = false;
	if((state.size() >= 4) && ((state[state.size() - 4][0] == last[0]) || (state[state.size() - 4][1] == last[1])) ){
		vector<string>state1 = state;
		state1[state1.size() - 4] = last;
		state1.pop_back();
		ans = calc_ans(state1);
	}
	if((state.size() >= 2) && ((state[state.size() - 2][0] == last[0]) || (state[state.size() - 2][1] == last[1])) ){
		vector<string>state1 = state;
		state1[state1.size() - 2] = last;
		state1.pop_back();
		ans = ans || calc_ans(state1);
	}
	dp[state] = ans ;
	return ans ;
}

int main(){
	ll n; cin >> n;
	vector<string> cards(n);

	for (int i = 0; i < n; ++i)cin >> cards[i];

	bool answer = calc_ans(cards);
	if(answer)cout << "YES"<< endl;
	else cout << "NO"<< endl;
}