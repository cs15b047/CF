#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;
map<ll,ll> dp;

ll calc_ans(ll n){
	if(dp.find(n) != dp.end())return dp[n];
	else{
		if(n % 2 == 0)dp[n] = 1 - calc_ans(n / 2);
		else dp[n] = max(1 - calc_ans(n - 1), 1 - calc_ans(n + 1));
		return dp[n];
	}
}

int main(){
	ll t; cin >> t;
	for(int q=0;q<t;q++){
		ll n; cin >> n;
		dp.clear();
		dp[1] = 1;
		dp[0] = 0;
		ll ans = calc_ans(n);
		if(dp[n] == 0){cout << "Lose" << endl;fflush(stdout);string str;cin >>str;}
		else{
			cout <<"Win" << endl;
			ll curr = n;
			while(curr != 0){
				if(curr % 2 == 0){cout << "/2" << endl;curr/=2;}
				else{
					if(dp[curr - 1] == 0){cout << "-1" << endl;curr--;}
					else {cout << "+1" << endl;curr++;}
				}
				fflush(stdout);
				string str;
				cin >> str;
				if(str == "/2")curr = curr/2;
				else if(str == "-1")curr--;
				else if(str == "+1")curr++;
				else if(str == "GG")break;
			}
		}
	}
}