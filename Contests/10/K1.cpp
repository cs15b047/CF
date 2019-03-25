#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;
int main(){
	ll t;cin>>t;
	for(int i=0;i<t;i++){

		ll n;cin>>n ;
		// cout << n << endl ;
		int first_from_left_place = -1;
		ll tmp = n;
		int j= 0 ;
		while(tmp != 0){
			if(tmp % 2 != 0)first_from_left_place = j;
			tmp = tmp / 10 ;
			j++;
		}
		ll ans = -1;
		if(first_from_left_place == -1)ans = 0;
		else if(first_from_left_place == 0)ans = 1;
		else{
			ll val = n % (ll)pow(10,first_from_left_place) ;
			ll num = 0;
			for(int q=0;q<first_from_left_place;q++)num += 8 *(ll)pow(10,q);
			ll n2 = (ll)pow(10,first_from_left_place) - num ;

			int digit = (n / (ll)pow(10,first_from_left_place)) % 10 ;
			// cout << digit << endl ;

			if(digit == 9){
				ans = val + n2 ;
				// cout << "YO";
			}
			else{
				// if((ll)pow(10,first_from_left_place+1) > n || ((n/ (ll)pow(10,first_from_left_place+1)) % 2 == 0))
				ans = min(val + n2, (ll)pow(10,first_from_left_place) - val) ;
				// else{
				// 	ans = val + n2 ;
				// }
			}
		}
		cout <<"Case #"<<(i+1)<<": "<< ans << endl ;
	}
}