// B. Maximum Submatrix 2 --> # 221 - div 1
// answer(col) = Max area starting from col as leftmost column
// Calculate for each position in each row, the rightmost point of streak of 1's containing this pt
// arrange in descending order of the above values and iterate over them and find max area.
/*
Like:
11111
11110
11000
10000
*/
#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll n, m; scanf("%lld%lld",&n,&m);
	vector<string> grid(n);
	for(ll i = 0;i < n;i++){
		char s[5001];
		scanf("%s",s);string temp(s);grid[i] = temp;
	}

	vector<ll> answer_col(m);
	vector<vector<ll>> cts_ends(m + 1);

	for(ll i = 0;i < n;i++){
		ll j = m - 1;
		while(j >= 0){
			while(j >= 0 && grid[i][j] == '0')j--;
			if(j < 0)break;
			ll cts_end = j;
			while(j >= 0 && grid[i][j] == '1'){
				cts_ends[j].push_back(cts_end);
				j--;
			}
		}
	}
	// for(ll j=0;j<m;j++){
	// 	for(auto it:cts_ends[j])cout <<it << " ";
	// 	cout << endl;
	// }

	for(ll j = 0;j < m; j++){
		sort(cts_ends[j].begin(),cts_ends[j].end(), greater<ll>());
		// for(auto it:cts_ends[j])cout <<it << " ";
		// cout << endl;
		ll answer = !cts_ends[j].empty();
		for(ll i = 1;i <= cts_ends[j].size();i++){
			answer = max(answer, (cts_ends[j][i - 1] - j + 1)*i);
		}
		answer_col[j] = answer;
	}
	ll final_answer = 0;
	for(auto it:answer_col)final_answer = max(final_answer, it);

	printf("%lld\n",final_answer );
}