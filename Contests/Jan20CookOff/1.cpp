#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll mod = 1e9 + 7;

vector<ll> get_bit_repr(ll num){
	vector<ll> answer(65, 0);
	ll idx = 0;
	while(idx <= 64){
		answer[idx] = (num % 2);
		num = num / 2;
		idx++;
	}
	return answer;
}

int main(){
	ll t; scanf("%lld",&t);
	for(int q = 0;q < t;q++){
		ll left, right; scanf("%lld%lld",&left, &right);
		ll answer = 0;
		if(left == 0)printf("0\n");
		else{
			vector<ll> bit_repr_left = get_bit_repr(left);
			ll i = 0, j =0;
			while(i < bit_repr_left.size()){
				if(bit_repr_left[i] == 1){
					// j = i + 1;
					// while(j < 64 && bit_repr_left[j] == 1)j++;
					// for(int k = i;k < j;k++){
					// 	ll tmp = (ll)pow(2, j) + ((left >> j) << j) ;
					// 	// cout << tmp << endl;
					// 	answer = (answer + ((min(tmp, right + 1) - left)% mod * ((ll)pow(2, k)% mod)) % mod) % mod;
					// }
					// i = j;
					ll tmp = left + ((ll)pow(2, i) - (left & (ll)(pow(2, i) - 1)));

					ll range = ((min(tmp, right + 1) - left)% mod);
					ll multiplier = (ll)pow(2, i)% mod;
					answer = (answer + ((range * multiplier) % mod)) % mod;
				}
				i++;
			}
			printf("%lld\n", answer);
		}
	}
}