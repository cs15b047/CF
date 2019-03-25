// Compression Edu Round 59 D
// If matrix can be compressed by 2 coprime numbers a and b, then it can be compressed by a * b
// Get prime factors of dimension and see upto which power of prime number compression is possible, by actually compressing and checking
// multiply all of prime^power togther to get answer
#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

string convert(char x){
	if(x == '0')return "0000";
	if(x == '1')return "0001";
	if(x == '2')return "0010";
	if(x == '3')return "0011";
	if(x == '4')return "0100";
	if(x == '5')return "0101";
	if(x == '6')return "0110";
	if(x == '7')return "0111";
	if(x == '8')return "1000";
	if(x == '9')return "1001";
	if(x == 'A')return "1010";
	if(x == 'B')return "1011";
	if(x == 'C')return "1100";
	if(x == 'D')return "1101";
	if(x == 'E')return "1110";
	if(x == 'F')return "1111";
	return "ajay";
}

int main(){
	ll n; scanf("%lld",&n);

	vector<string> orig_grid(n), grid(n);
	for(ll i=0;i<n;i++){
		char s[1301];
		scanf("%s",s);
		string str(s);
		orig_grid[i] = str;
	}
	for(ll i=0;i<n;i++){
		for(ll j = 0;j<n/4;j++){
			grid[i] += convert(orig_grid[i][j]);
		}
	}
	// for(auto it:grid)cout << it << endl;
	vector<bool> not_prime(n + 1);
	vector<ll> spf(n + 1);
	for(ll i = 2;i <= n;i++){
		if(!not_prime[i]){
			spf[i] = i;
			for(ll j = i*i;j <= n;j += i){
				not_prime[j] = 1;
				spf[j] = i;
			}
		}
	}
	map<ll,ll> factor_pwr;
	ll tmp = n;
	while(tmp > 1){
		ll fact = spf[tmp];
		while(tmp % fact == 0){
			factor_pwr[fact]++;
			tmp = tmp/ fact ;
		}
	}

	// for(auto it:factor_pwr){
	// 	cout << it.first << " "<< it.second ;
	// }

	map<ll,ll> factor_blkpwr;

	for(auto it: factor_pwr){
		vector<string> new_grid = grid;
		ll x = it.first;
		for(ll pwr = 1;pwr <= it.second;pwr++){
			// for(auto it:new_grid)cout << it << endl;
			ll sz = n / (ll)pow(x, pwr - 1);
			bool flag = true;
			for(ll i = 0;i < sz / x; i++){
				for(ll j = 0;j < sz / x; j++){
					char blk_char = new_grid[i*x][j*x];
					ll base1 = i*x, base2 = j*x;
					for(ll k = 0;k < x;k++){
						for(ll l = 0;l<x;l++){
							if(new_grid[base1 + k][base2 + l] != blk_char){
								flag = false;
								break;
							}
						}
						if(!flag)break;
					}
					if(!flag)break;
				}
				if(!flag)break;
			}
			if(flag){
				vector<string> tmp_new_grid(sz / x);
				factor_blkpwr[x]++;
				for(ll i = 0;i < sz / x; i++){
					for(ll j = 0;j < sz / x; j++){
						tmp_new_grid[i] += new_grid[i*x][j*x];
					}
				}
				// for(auto it:tmp_new_grid)cout << it << endl;
				new_grid.clear();
				new_grid = tmp_new_grid ;
			}
			else break;
		}
	}

	ll final_answer = 1;
	for(auto it:factor_blkpwr){
		final_answer = final_answer * (ll)pow(it.first, it.second) ;
	}
	printf("%lld\n",final_answer );
}