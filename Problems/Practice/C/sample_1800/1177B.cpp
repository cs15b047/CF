#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll k; cin >> k;
	vector<ll> starts;
	ll curr = 1, num_digits = 1, num = 9;
	while(curr <= k){
		starts.push_back(curr);
		curr += (num_digits * 9 * pow(10, num_digits - 1));
		num_digits++;
	}

	ll digits = starts.size();
	ll value = pow(10, digits - 1) +  (k - starts.back())/digits; // ceil((double)(k - starts.back())/(double)digits);
	ll pos_in_value = (k - starts.back()) % digits;
	ll ans;
	
	ans  = (value / (ll)pow(10, (digits - 1 - pos_in_value))) % 10;
	cout << ans << endl;
	


}