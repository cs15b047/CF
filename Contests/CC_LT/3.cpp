#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

ll m;
vector<ll> primes, relevant,pwrs;
set<ll> answers;
map<ll, bool> vis;

void rec_fn(ll idx, ll val){
	if(idx == relevant.size()){
		answers.insert(val);
		return;
	}
	else{
		for(int i=0;i <= pwrs[idx];i++){
			ll gadbad = (ll)pow(relevant[idx], (ll)i);
			if( ( gadbad >= 0 && gadbad <= m) && (val <= m / gadbad) && (val * gadbad <= m) ){
				ll tmp = val * gadbad;
				rec_fn(idx + 1, tmp);
			}
			else return;
		}
	}
}


int main(){
	ll t; cin >> t;
	// preprocess
	vector<bool> is_prime(1e7 + 1, 1);
	for(ll num = 2; num <= (ll)1e7; num++){
		if(is_prime[num]){
			primes.push_back(num);
			for(ll j = num * num; j <= (ll)1e7; j+=num){
				is_prime[j] = 0;
			}
		}
	}

	for(int i=0;i<t;i++){
		cin >> m;
		relevant.clear();pwrs.clear();answers.clear();
		for(auto it: primes){
			if(m % it == 0){
				relevant.push_back(it);
				ll tmp = m,pwr = 0;
				while(tmp % it  == 0){pwr++;tmp/=it;}
				pwrs.push_back(2*pwr);
			}
		}

		// for(int i=0;i<=3;i++){
		// 	ll p = 1e9 + 7;
		// 	cout << (ll)pow(p, (ll)i) << endl;
		// }

		rec_fn(0,1);
		cout << answers.size() << endl;
		// sort(answers.begin(),answers.end());
		for(auto it:answers)cout << it + m << endl;
	}
}