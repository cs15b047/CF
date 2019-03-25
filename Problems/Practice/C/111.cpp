//C. Another Problem on Strings # 112 -2
// Taking consecutively(not literally) occurring k 1's, calculate, how much 0 s are there to left and right of extreme 1s and ans += (# left 0s + 1)x(#right 0s +1)
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll k; cin >> k;
	string str; cin >> str ;

	vector<ll>one_posns,zero_lengths;
	for(int index=0;index < str.length();){
		if(str[index] == '1')one_posns.push_back(index++);
		else{
			ll strt = index;
			while(index < str.length() && str[index] == '0')index++;
			zero_lengths.push_back(index - strt);
		}
	}	
	ll ans = 0;
	if(k == 0){
		for(int i=0;i<zero_lengths.size();i++)ans += (zero_lengths[i]*(zero_lengths[i]+1))/2 ;
	}
	else{
		for(ll i=0;i <= (ll)one_posns.size() - k;i++){
			ll strt_extend = 0,end_extend =0;
			ll prev_ind,nxt_ind;
			
			if(i == 0)prev_ind = 0;
			else prev_ind = one_posns[i-1] + 1;
			if(i == one_posns.size()-k)nxt_ind = str.length() - 1;
			else nxt_ind = one_posns[i + k] - 1;

			strt_extend = one_posns[i] - prev_ind ;
			end_extend = nxt_ind - one_posns[i + k - 1];

			ans += (strt_extend + 1)*(end_extend + 1);
		}
	}
	cout << ans << endl ;
}