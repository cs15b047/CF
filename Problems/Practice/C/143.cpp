// D. Little Girl and Maximum XOR #169 - div 1
//Common portion of bit repr of l and r will not contibute, and 1 point of difference will be 0 in l and 1 in r as l < r. So, further bits after that can all be made 1 and in r, 0 (as those numbers will stay  <= r & >= l due to 1st point of 0 and 1). So, answer = 2^(#non-common bits - 1)
#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

vector<ll> get_bit_repr(ll num){
	vector<ll> answer;
	for(ll i = 1;i <= 64;i++){
		answer.push_back(num % 2);
		num = num / 2;
	}
	return answer;
}

int main(){
	ll l,r; cin >> l >> r;
	ll answer = 0;
	if(l == r)answer = 0;
	else{
		vector<ll> num1, num2; num1 = get_bit_repr(l); num2 = get_bit_repr(r);
		// for(auto it:num1)cout<<it;
		// cout<< endl;
		// for(auto it:num2)cout<<it;
		// cout<< endl;
		
		ll index;
		for(int i=64;i>=1;i--){
			if(num1[i - 1] != num2[i - 1]){
				index = i ;
				break;
			}
		}
		// cout << index << endl;
		answer = (ll)pow(2, index) - 1;
	}
	cout << answer << endl;

}