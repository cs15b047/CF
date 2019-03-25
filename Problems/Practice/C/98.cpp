//A. Little Elephant and Interval # 129 - 1
// calculate answer for 1 to number and then do r - l for a query
// to calc ans, add ans for earlier decimal  places(from LSB) and take special care for first decimal place
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<ll> dp;

ll calc_ans(ll n){
	if(n == 0)return 0;
	else if(n < 10)return n;
	else if(n < 100){
		ll ans = 9;
		for(int i=1;i<=9;i++){
			if(n >= 11*i)ans++;
			else break;
		}
		return ans;
	}
	else{
		ll num_digits=0;
		ll tmp = n,rem = n % 10;
		while(tmp != 0){
			rem = tmp % 10;
			tmp /= 10;
			num_digits++;
		}
		ll ans = 9 + 9 ;

		for(ll i = 3;i<num_digits;i++)ans += 9 * (ll)pow(10, i - 2);

		ans += (rem - 1) * (ll)pow(10, num_digits - 2);
		ll middle_val = (n - rem * (ll)pow(10,num_digits-1) - (n % 10))/10 ;
		// printf("%lld\n",middle_val );
		ans += middle_val;
		ans += (rem <= (n % 10)) ;
		return ans;
	}
}

int main(){
	ll left, right; cin >> left >> right ;
	cout << (calc_ans(right) - calc_ans(left - 1)) << endl ;


}