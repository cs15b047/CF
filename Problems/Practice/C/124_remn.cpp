#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll mod = 1e9+7 ;
map<vector<ll>,ll> dp ;
vector<ll> counts;
void calc_ans(){
	if(dp.find(counts) != dp.end())return;
	if(counts.size() == 2)dp[counts] = 1;
	else{
		ll ans = 0;
		ll sz = counts.size();
		for(int i = 1;i < sz;i++){
			if(counts[i] > 1){
				counts[i]--;
				calc_ans();
				ans = (ans + dp[counts]) % mod;
				counts[i]++;
			}
			if(i == sz -1 && counts[i] == 1){
				counts.pop_back();
				calc_ans();
				ans = (ans + dp[counts]) % mod;
				counts.push_back(1);
			}
		}
		dp[counts] = ans ;
	}
}

int main(){
	ll k; cin >> k;
	counts.resize(k+1);
	for(int i=k;i>=1;i--)scanf("%lld",&counts[i]);
	calc_ans();
	printf("%lld\n",dp[counts] );
}