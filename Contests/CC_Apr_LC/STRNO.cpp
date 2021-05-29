#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll tests; cin >> tests;
	vector<bool> is_prime(100001, true);
	vector<ll> primes;
	is_prime[1] = false;
	for(ll i = 2;i <= 100000;i++){
		if(is_prime[i]){
			for(ll j = i * i;j <= 100000;j += i){
				is_prime[j] = false;
			}
			primes.push_back(i);
		}
	}
	for(int t = 0;t < tests;t++){
		ll X, K; cin >> X >> K;
		ll pwrs = 0;
		for(int i = 0;(i < primes.size()) && (primes[i] * primes[i] <= X);i++){
			if(X % primes[i] == 0){
				while(X % primes[i] == 0){
					X = X / primes[i];
					pwrs++;
				}
			}
		}
		if(X > 1){
			pwrs++;
		}
		if(pwrs >= K){
			cout << 1 << endl;
		} else {
			cout << 0 << endl;
		}
	}

}