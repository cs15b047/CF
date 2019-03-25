//B. Good Sequences
// Keep a cumulative map, which stores prime factor ---> max ans achieved by a number having that prime factor
// for each element, calc answer ending at element. Get prime factorizn of num using sieve and smallest prime factor, and corresponding answers for prime factor in map, and update map
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){

	bool not_prime[100001]={};
	ll spf[100001] = {};
	for(ll i=2;i<=100000;i++){
		if(!not_prime[i]){
			spf[i] = i;
			for(ll j = i*i;j<=100000;j+=i){
				if(!not_prime[j]){
					spf[j] = i;
					not_prime[j] = 1;
				}
			}
		}
	}

	ll n ; cin >> n ;
	vector<ll> a(n);for(int i=0;i<n;i++)cin >> a[i] ;

	map<ll,ll> factor_ans_map;
	vector<ll> answer_ending(n);

	for(int i=0;i<n;i++){
		ll num = a[i];
		vector<ll> prime_factors;
		while(num != 1){
			ll factor = spf[num];
			prime_factors.push_back(factor);
			while(num % factor == 0)num /= factor;
		}
		answer_ending[i] = 1;
		for(auto pf:prime_factors){
			answer_ending[i] = max(answer_ending[i], factor_ans_map[pf] + 1);
		}
		for(auto pf: prime_factors){
			factor_ans_map[pf] = max(factor_ans_map[pf], answer_ending[i]);
		}
	}
	ll answer = 0;
	for(int i=0;i<n;i++)answer = max(answer, answer_ending[i]);
	cout << answer << endl;
}