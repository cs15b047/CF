#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll k; cin >> k;

	vector<ll> start_posns;
	ll curr = 1;
	ll offset = 9, num_digits = 1;
	while(curr <= k){
		start_posns.push_back(curr);
		curr += offset * num_digits;
		offset = offset * 10;
		num_digits++;
	}

	auto it = upper_bound(start_posns.begin(), start_posns.end(), k);
	it--;
	ll posn = *it, digits = it - start_posns.begin() + 1;
	ll num = k - posn + 1, actual_number;
	actual_number = (ll)pow(10, digits - 1) + ceil((double)num / (double)digits) - 1;
	ll remndr = num % digits;
	ll digit_num = (digits - remndr + 1);
	
	ll answer;
	if(remndr == 0){
		answer = actual_number % 10;
	} else{
		ll dig = (actual_number / (ll)pow(10, digit_num - 1)) % 10;
		answer = dig;
	}
	cout << answer << endl;
}