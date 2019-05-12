#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll gcd(ll a, ll b){
	if(b == 0)return a;
	return gcd(b, a% b);
}

ll lcm(ll a, ll b){return (a*b)/gcd(a,b);}

int main(){
	ll a,b; cin >> a >> b;
	if( gcd(a,b) == a || gcd(a,b) == b || a == b - 1  || a - 1 == b)cout << 0 << endl;
	else{
		vector<ll> is_prime(1e6 + 1, 1), primes;
		is_prime[1] = 0;
		for(ll i=2;i<=100000;i++){
			if(is_prime[i] == 1){
				for(ll j = i*i;j <= 100000;j += i){
					is_prime[j] = 0;
				}
				primes.push_back(i);
			}
		}
		ll ans = 1;
		set<ll> pr;
		for(auto it:primes){
			if(a % it == b % it)pr.insert(it);
		}
		for(auto it: pr){
			ll num = 1;
			while(a % (num * it) == b % (num * it))num = num * it;
			ans = ans * num ;
		}
		cout << (ans - (a % ans)) << endl;
	}
}