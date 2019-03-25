//B. Sagheer, the Hausmeister # 417 - 2
// For all combinations of stairs taken, calc ans, and take minm. (Mostly handling corner cases)
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<ll> first_pos,last_pos;
ll n,m;
ll calc_ans(ll seq_num, ll furthest_row){
	vector<int> sequence;
	for(int i=0;i<furthest_row+1;i++){
		sequence.push_back(seq_num%2);
		seq_num = seq_num/2;
	}
	ll ans = 0;
	for(int i=0;i<furthest_row;i++){
		if(sequence[i] == sequence[i+1]){
			if(first_pos[i] == -1)ans++;
			else{
				if(sequence[i] == 0)ans += 2*last_pos[i] + 1;
				else ans += 2*((m+1)-first_pos[i]) + 1;
			}
		}
		else ans += m+2;
	}
	if(sequence.back() == 1)ans += ((m+1) - first_pos.back());
	else ans += last_pos.back();
	// for(auto it:sequence)cout << it << " ";cout << endl;
	// cout << ans << endl;
	return ans;
}

int main(){
	cin >> n >> m ;
	vector<string> grid(n);for(int i=0;i<n;i++)cin >> grid[n-1-i] ;
	first_pos.clear();last_pos.clear();
	int i = 0,flag=0;
	for(i=n-1;i>=0;i--){
		for(int j = 0;j<m+2;j++){
			if(grid[i][j] == '1'){
				flag = 1;
				break;
			}
		}
		if(flag == 1)break;
	}
	int furthest_row = i;
	for(int k = i;k>=0;k--){
		int flg=-1;
		for(int j = 0;j < m + 2;j++){
			if(grid[k][j] == '1'){first_pos.push_back(j);flg = 1;break;}
		}
		if(flg == -1)first_pos.push_back(-1);
		for(int j = m+1;j >= 0;j--){
			if(grid[k][j] == '1'){last_pos.push_back(j);flg = 1;break;}
		}
		if(flg == -1)last_pos.push_back(-1);
	}
	// cout << furthest_row << endl;
	reverse(first_pos.begin(),first_pos.end());
	reverse(last_pos.begin(),last_pos.end());

	// for(auto it:first_pos)cout << it << " "; cout << endl;
	// for(auto it:last_pos)cout << it << " "; cout << endl;

	vector<ll> dp((ll)pow(2,n));
	if(i == -1)cout << 0 << endl;
	else{
		for(int j = 0;j < (ll)pow(2,furthest_row);j++){
			ll num = j << 1 ;
			// cout << num << endl;
			dp[j] = calc_ans(num, furthest_row);
		}
		ll minm = 1e18;
		for(int j=0;j<(ll)pow(2,furthest_row);j++){
			minm = min(minm,dp[j]);
		}
		cout<< minm << endl;
	}
}